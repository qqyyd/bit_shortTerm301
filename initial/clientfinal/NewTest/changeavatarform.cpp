#include "changeavatarform.h"
#include "ui_changeavatarform.h"
#include <QPainterPath>

ChangeAvatarForm::ChangeAvatarForm(void *father, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeAvatarForm)
{
    ui->setupUi(this);
    //窗口设置
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags (Qt::FramelessWindowHint);
    setWindowModality(Qt::ApplicationModal);
    //入场动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    //启动设置

    m_pDivWidget = new QWidget(ui->scrollArea);
    m_pDivWidget->setAttribute(Qt::WA_TranslucentBackground);
    m_pDivWidget->hide();
    m_pDivWidget->installEventFilter(this);

    this->father = father;

    connect(ui->horizontalSlider,
            &QSlider::valueChanged,
            this,
            &ChangeAvatarForm::onScaledChanged);

    connect(ui->pushButton_anti,
            &QPushButton::clicked,
            std::bind(&ChangeAvatarForm::RotateAvatar,this, false));

    connect(ui->pushButton_clock,
            &QPushButton::clicked,
            std::bind(&ChangeAvatarForm::RotateAvatar, this, true));

    connect(myCommunicationClient::myClient,
            &Communication_client::head_image_change_state,
            this,
            [=](int state){
       if (state == 1)
       {
           QMessageBox::information(this, "恭喜", "头像更换成功！");
       }
           //change success
       if (state == 0)
       {
           QMessageBox::critical(this, "错误", "头像更换失败！");
       }
           //unknow error
    });

}

ChangeAvatarForm::~ChangeAvatarForm()
{
    delete ui;
}


//旋转图片
void ChangeAvatarForm::RotateAvatar(bool bClock)
{
    QPixmap pixmap = *(ui->label_avatar->pixmap());
    QMatrix matrix;
    matrix.rotate(bClock ? 90 : -90);
    pixmap = pixmap.transformed(matrix);
    ui->label_avatar->setPixmap(pixmap);
}

//加载头像
void ChangeAvatarForm::LoadAvatar(const QPixmap& pixmap)
{
    m_sourceAvatar = pixmap;
    int nSliderMinmum = 0;
    QPixmap scaledPixmap;
    if (m_sourceAvatar.width() > m_sourceAvatar.height())
    {
        scaledPixmap = m_sourceAvatar.scaledToHeight(ui->scrollArea->height());
        nSliderMinmum = scaledPixmap.height() * ui->horizontalSlider->maximum() / m_sourceAvatar.height();
    }
    else
    {
        scaledPixmap = m_sourceAvatar.scaledToWidth(ui->scrollArea->width());
        nSliderMinmum = scaledPixmap.width() * ui->horizontalSlider->maximum() / m_sourceAvatar.width();
    }
    ui->scrollAreaWidgetContents->resize(m_sourceAvatar.size());
    ui->horizontalSlider->setEnabled(true);
    ui->horizontalSlider->setMinimum(nSliderMinmum);
    ui->horizontalSlider->setValue(nSliderMinmum);
    ui->label_avatar->setPixmap(scaledPixmap);
    m_pDivWidget->show();
}

//截取头像
bool ChangeAvatarForm::eventFilter(QObject *watched, QEvent *event)
{
    if (m_pDivWidget == watched && QEvent::Paint == event->type())	//绘制遮罩层
    {
        m_pDivWidget->resize(ui->scrollArea->size());
        QPainterPath path;
        path.addRect(m_pDivWidget->geometry());
        path.addEllipse(m_pDivWidget->geometry().adjusted(2, 2, -2, -2));
        QPainter p(m_pDivWidget);
        p.setRenderHint(QPainter::Antialiasing);
        p.setBrush(QColor(100, 100, 100, 200));
        p.setClipPath(path);
        p.drawRect(m_pDivWidget->geometry());
    }
    return QWidget::eventFilter(watched, event);
}


//关闭动画
bool ChangeAvatarForm::closeChangeAvatarForm()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));

    return true;
}
void ChangeAvatarForm::on_closeBtn_clicked()
{
    closeChangeAvatarForm();
}

//上传图片
void ChangeAvatarForm::on_pushButton_upload_clicked()
{
    QString strFilePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择上传图片"), "./", "*.jpg;;*.png;;*.bmp", nullptr, QFileDialog::DontUseNativeDialog);

    if (strFilePath.isEmpty())
    {
        return;
    }
    LoadAvatar(QPixmap(strFilePath));
}


//缩放条
void ChangeAvatarForm::onScaledChanged(int nValue)
{
    QPixmap pixmap = m_sourceAvatar.scaled(m_sourceAvatar.size() * ((double)nValue / ui->horizontalSlider->maximum()));
    ui->scrollAreaWidgetContents->resize(pixmap.size());
    ui->label_avatar->setPixmap(pixmap);
}

//取消
void ChangeAvatarForm::on_pushButton_cancel_clicked()
{
    m_pDivWidget->hide();
    ui->label_avatar->clear();

    close();
}

//确定
void ChangeAvatarForm::on_pushButton_ok_clicked()
{
    const QPixmap updateAvatar = *(ui->label_avatar->pixmap());
    myCommunicationClient::myClient->change_head_image(updateAvatar.toImage());
    ((PersonalForm *)father)->circleAvatar(updateAvatar.toImage());
    close();
//    if ( updateAvatar = ui->label_avatar->pixmap())
//    {
//        //上传到服务器

//        myCommunicationClient::myClient->change_head_image(updateAvatar);

//        emit updateAvatar(*pAvatar);

//    }

}
