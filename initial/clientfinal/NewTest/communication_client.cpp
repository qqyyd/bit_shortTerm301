#include "communication_client.h"

Communication_client::Communication_client(QObject *parent) : QObject(parent)
{
}

bool Communication_client::try_connection(QString ip, int port) {
    if (client!=NULL) delete client;
    client = new QTcpSocket();
    client->connectToHost(QHostAddress(ip),port);
    connect(client,&QTcpSocket::readyRead,this,[=](){
        Reader::recv += client->readAll();
        qDebug()<<"ready "<<Reader::recv.size()<<endl;;
        qDebug()<<"size "<<Reader::recv.mid(0,6).toInt()+6<<endl;
        if (Reader::recv.size()==Reader::recv.mid(0,6).toInt()+6) {
            qDebug()<<"recvsize "<<Reader::recv.size()<<endl;;
            QByteArray recv = Reader::recv.mid(6,Reader::recv.size()-1 - 6 + 1);
            Reader::recv.clear();
//            qDebug()<<QString(recv)<<endl;
            QString type = TCP::decode_head(recv);
            qDebug()<<"type:: "<<type<<endl;

            if (type=="login_success") emit login_feedback(1);
            if (type=="login_error-wrong_password") emit login_feedback(0);
            if (type=="login_error-id_not_exist") emit login_feedback(-1);
            if (type=="register_success") emit register_feedback(1);
            if (type=="register_failed-idNumber_occupied") emit register_feedback(0);

            if (type=="initialize_friend_list") get_initial_friend_list(recv);
            if (type=="initialize_friend_chat_record") get_initial_chat_recode(recv);
            if (type=="initialize_friend_request_record") get_initial_request_recode(recv);

            if (type=="receive_new_string_from_someone") get_string_message(recv);

            if (type=="find_friend_result") get_find_friend_result(recv);
            if (type=="new_friend_request") get_new_friend_add_request(recv);
            if (type=="friend_add_success") get_new_friend(recv);
            if (type=="friend_add_reject") get_rejected_friend_info(recv);

            if (type=="head_image_change_success") emit head_image_change_state(1);
            if (type=="head_image_change_failed") emit head_image_change_state(0);

            if (type=="usersMotto_change_success") emit usersMotto_change_state(1);
            if (type=="usersMotto_change_failed") emit usersMotto_change_state(0);
        }
//        get_string_message(recv);
    });
    if (client->waitForConnected(3000)) {
        return true;
    }else{
        return false;
    }
}

bool Communication_client::send_string_message(QString text, QString from, QString to) {
    client->write(TCP::bind(TCP::encode_send_string_message(text,from,to).toUtf8()));
    return true;
}

bool Communication_client::add_friend(QString verifyMessage, QString from, QString to) {
    client->write(TCP::bind(TCP::encode_add_friend(verifyMessage,from,to).toUtf8()));
    return true;
}

bool Communication_client::find_friend(QString from, QString to) {
    client->write(TCP::bind(TCP::encode_find_friend(from,to).toUtf8()));
    return true;
}

bool Communication_client::friend_accept(QString opter, QString original) {
//    qDebug()<<"begin"<<endl;
//    qDebug()<<"qDebug2"<<TCP::encode_deal_new_friend(opter,original,"accept")<<endl;
    client->write(TCP::bind(TCP::encode_deal_new_friend(opter,original,"accept").toUtf8()));
    return true;
}
bool Communication_client::friend_reject(QString opter, QString original) {
    client->write(TCP::bind(TCP::encode_deal_new_friend(opter,original,"reject").toUtf8()));
    return true;
}

bool Communication_client::try_to_login(QString idNumber, QString password) {
    client->write(TCP::bind(TCP::encode_login_register("login",idNumber,password).toUtf8()));
    return true;
}

bool Communication_client::try_to_register(QString idNumber, QString password) {
    client->write(TCP::bind(TCP::encode_login_register("register",idNumber,password).toUtf8()));
    return true;
}

QByteArray ImageToByteArray(QImage img){
    QByteArray ba;
    QBuffer buf(&ba);
    img.save(&buf, "PNG");

//    QByteArray compressed = qCompress(ba, 1); // better just open file with QFile, load data, compress and toHex?
//    QString rStr = QString::fromLatin1(compressed.data(), compressed.size());
//    qDebug() << rStr << endl;

    return ba;
}

bool Communication_client::change_head_image(const QImage image) {
//    client->write(TCP::bind(TCP::encode_change_image().toUtf8()+ImageToByteArray(image));
    client->write(TCP::bind(QString("07").toUtf8() + ImageToByteArray(image).toBase64()));
    return true;
}

bool Communication_client::change_userMotto(QString newMotto) {
    client->write(TCP::bind(TCP::encode_change_usersMotto(newMotto).toUtf8()));
    return true;
}

void Communication_client::get_string_message(QByteArray message) {
    QVector<QString> messageList = TCP::decode_string_message(message);
    emit new_string_message_ready(messageList[0],messageList[1]);
}

void Communication_client::get_initial_friend_list(QByteArray message) {
    QVector<PersonalInfo> friendList = TCP::decode_initial_friend_list(message);
    qDebug()<<"friendlistsize: "<<friendList.size()<<endl;
    emit friendList_ready(friendList);
}
void Communication_client::get_initial_chat_recode(QByteArray message) {
    QVector<QPair<QString,QVector<QString>>> chatRecode = TCP::decode_initial_chat_recode(message);
    emit chat_recode_ready(chatRecode);
}

void Communication_client::get_initial_request_recode(QByteArray message) {
    QVector<QPair<PersonalInfo,QString>> requestRecode = TCP::decode_initial_request_recode(message);
    emit request_recode_ready(requestRecode);

}

void Communication_client::get_find_friend_result(QByteArray message) {
    QString info = TCP::decode_friend_add_try(message);
    emit find_friend_result(info);
}

void Communication_client::get_new_friend_add_request(QByteArray message) {
    QPair<PersonalInfo,QString> verify_try = TCP::decode_friend_request_info(message);
    PersonalInfo person_info = verify_try.first;
    QString verify_text = verify_try.second;
    emit friend_request(person_info,verify_text);
}

void Communication_client::get_new_friend(QByteArray message) {
    PersonalInfo person_info = TCP::decode_friend_info(message);
    emit new_friend_added(person_info);
}

void Communication_client::get_rejected_friend_info(QByteArray message) {
//    PersonalInfo person_info = TCP::decode_friend_info(message);
//    emit be_rejected(person_info);
}

