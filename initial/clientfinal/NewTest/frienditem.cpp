#include "frienditem.h"
#include "ui_frienditem.h"
#include <QPainter>
#include <QPainterPath>
#include <QPixmap>
#include <QString>
#include "chatform.h"

FriendItem::FriendItem(PersonalInfo person, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendItem)
{
    ui->setupUi(this);

    circleAvatar(person.image);
    setFriendName(person.idNumber);
//    setAttribute(Qt::WA_TranslucentBackground);
//    setWindowFlags (Qt::FramelessWindowHint);
}

FriendItem::~FriendItem()
{
    delete ui;
}

void FriendItem::circleAvatar(QImage avatar)
{
    int w = ui->friendAvatar->width();
    int h = ui->friendAvatar->height();
    QPixmap pixmapa(QPixmap::fromImage(avatar));
    QPixmap pixmap(w,h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
       QPainterPath path;
       path.addEllipse(0, 0, w, h);    //绘制椭圆
       painter.setClipPath(path);
       painter.drawPixmap(0, 0, w, h, pixmapa);

       ui->friendAvatar->setPixmap(pixmap);
}

void FriendItem::setFriendName(QString _friendName)
{
    ui->friendName->setText(_friendName); // 好友姓名 friendName;
    this->friendName = _friendName; // 需要保存一个好友姓名，用来唯一标识
}

void FriendItem::on_friendChatBtn_clicked()
{
//    ChatForm *chatForm = new ChatForm;
    /**************************************/
    makeChatform(friendName);
//    emit openChatForm(friendName);
    /**************************************/
//    chatForm->show();
}

/*********************************/

ChatForm* FriendItem::makeChatform(QString Name){
    if(NameToChatForm.keys().contains(Name)) //如果存在这个title的聊天室, 返回该指针，并setFocus
    {
        NameToChatForm[Name]->setFocus();
        return NameToChatForm[Name];
    }
    else
    {
        ChatForm *newChatForm = new ChatForm;
        newChatForm->setFriendName(Name);
        NameToChatForm.insert(Name, newChatForm); // 通过Name找到newChatForm
        ChatFormToName.insert(newChatForm, Name); // 通过newChatForm找到newChatForm
//        connect(newpm, SIGNAL(enteredText(QString)), this, SLOT(onPMSend(QString))); // 发送消息
//        connect(newpm, SIGNAL(voiceTalk(bool,bool)), this, SLOT(onVoiceTalk(bool,bool))); // 语音通话
//        connect(newpm, SIGNAL(closedWindow()), this, SLOT(onPMClosed()));
        connect(newChatForm, SIGNAL(ChatFormClosed()), this, SLOT(onChatFormClosed())); // 关闭窗口
        newChatForm->setChatFormName(Name); // 设置窗口Name
        newChatForm->init();
        newChatForm->show(); //显示窗口
        return newChatForm;
    }
}


void FriendItem::onChatFormClosed(){
    ChatForm* chatForm = qobject_cast<ChatForm*>(sender());
    NameToChatForm.remove(ChatFormToName[chatForm]);
    ChatFormToName.remove(chatForm);
}
/*********************************/

