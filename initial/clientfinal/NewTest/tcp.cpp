#include "tcp.h"
#include<QDebug>

QString TCP::separator = "<#^&r|`{>";
QString TCP::end = "<`!#>";
QByteArray TCP::bend = TCP::end.toUtf8();
TCP::TCP(QObject *parent) : QObject(parent){}

QString TCP::encode_send_string_message(QString message, QString from, QString to)
{
    return QString("01"+message+separator+from+separator+to);
}

QString TCP::encode_login_register(QString type, QString idNumber, QString password)
{
    QString type_id = "-1";
    if (type=="register") type_id="02";
    if (type=="login") type_id="03";
    qDebug()<<QString("%1"+idNumber+separator+password).arg(type_id)<<endl;
    return QString("%1"+idNumber+separator+password).arg(type_id);
}

QString TCP::encode_add_friend(QString verify, QString from, QString to)
{
    return QString("04"+verify+separator+from+separator+to);
}

QString TCP::encode_deal_new_friend(QString opter, QString original, QString type)
{
    QString type_id = "-1";
    if (type==QString("accept")) type_id="05";
    if (type==QString("reject")) type_id="06";
//    qDebug()<<type<<endl;
//    qDebug()<<QString("%1"+separator+opter+separator+original).arg(type_id)<<endl;
//    qDebug()<<"encodeend"<<endl;
    return QString("%1"+opter+separator+original).arg(type_id);
}

QString TCP::encode_change_image() {
    return QString("07");
}
QString TCP::encode_change_usersMotto(QString newMotto) {
    return QString("08"+newMotto);
}
QString TCP::encode_find_friend(QString from, QString to) {
    return QString("09"+from+separator+to);
}

QString TCP::decode_head(QByteArray recv)
{
    char type = recv[0];
//    qDebug()<<"type="<<type<<" "<<recv<<endl;
    if (type=='0') return "login_success";
    if (type=='1' && recv[2]=='2') return "login_error-id_not_exist";
    if (type=='1') return "login_error-wrong_password";
    if (type=='2') return "register_success";
    if (type=='3') return "register_failed-idNumber_occupied";

    if (type=='4' && recv[2]=='2') return "initialize_friend_chat_record";
    if (type=='4' && recv[2]=='3') return "initialize_friend_request_record";
    if (type=='4') return "initialize_friend_list";

    if (type=='5') return "receive_new_string_from_someone";

    if (type=='6') return "find_friend_result";
    if (type=='7') return "new_friend_request";
    if (type=='8') return "friend_add_success";
    if (type=='9') return "friend_add_reject";

    if (type=='1' && recv[1]=='0') return "head_image_change_success";
    if (type=='1' && recv[1]=='1') return "head_image_change_failed";
    if (type=='1' && recv[1]=='2') return "usersMotto_change_success";
    if (type=='1' && recv[1]=='3') return "usersMotto_change_failed";

    return "ERROR";
}

QVector<QString> TCP::decode_string_message(QString recv)
{
    //type | From_idNumber | message_string
    //return "receive_new_string_from_someone";
    QStringList list = recv.split(separator);
    QVector<QString> messageList;
    for (int i=1;i<list.size();i++) {
        messageList.push_back(list[i]);
    }
    return messageList;
}

const char separator[] = "<#^&r|`{>";
QVector<QByteArray> mysplit(QByteArray recv) {
    QVector<QByteArray> list;
    int lst = 0;
    for (int i=8;i<recv.size();i++) {
        bool isMatch = true;
        for (int j=i-8,k=0;j<=i && isMatch;j++,k++) {
            if ((char)recv[j]!=(char)separator[k]) isMatch=false;
        }
        if (isMatch) {
            list.push_back(recv.mid(lst,i-9 - lst + 1));
            lst = i+1;
        }
    }
    list.push_back(recv.mid(lst,recv.size()-1 - lst + 1));
    return list;
}

QVector<PersonalInfo> TCP::decode_initial_friend_list(QByteArray recv)
{
    //type | name1 | usersMotto1 | Image1 | name2 ...
    //return "initialize_friend_list";
    QVector<QByteArray> list = mysplit(recv);
    QVector<PersonalInfo> friendList;
    qDebug()<<"!@#!@3";
    for (int i=1;i<list.size();i+=3) {
        PersonalInfo person = PersonalInfo(list[i],list[i+1],QByteArray::fromBase64(list[i+2]));
        friendList.push_back(person);
    }
    return friendList;
}

QVector<QPair<QString,QVector<QString>>> TCP::decode_initial_chat_recode(QString recv) {
    //type | numbertot | friend_id_1 | tot | st1 | st2
    QStringList list = recv.split(separator);
    QVector<QPair<QString,QVector<QString>>> chatRecode;
    int totNumber = list[1].toInt();
    int iter = 2;
    for (int i=0;i<totNumber;i++) {
        QString friend_id = list[iter++];
        int len = list[iter++].toInt();
        QVector<QString> oneRecode;
        for (int j=0;j<len;j++) {
            oneRecode.push_back(list[iter++]);
        }
        chatRecode.push_back({friend_id,oneRecode});
    }
    return chatRecode;
}

QVector<QPair<PersonalInfo,QString>> TCP::decode_initial_request_recode(QByteArray recv) {
    //type | name1 | usersMotto1 | Image1 | verify1 | name2 ...
    QVector<QByteArray> list = mysplit(recv);
//    for (auto x : list) qDebug()<<x<<endl;
    QVector<QPair<PersonalInfo,QString>> requestList;
    for (int i=1;i<list.size();i+=4) {
        PersonalInfo person = PersonalInfo(list[i],list[i+1],QByteArray::fromBase64(list[i+2]));
        requestList.push_back({person,list[i+3]});
    }
    return requestList;
}



QString TCP::decode_friend_add_try(QString recv)
{
    //type | state_type
    QStringList list = recv.split(separator);
    return list[1];
}

QPair<PersonalInfo,QString> TCP::decode_friend_request_info(QByteArray recv)
{
    //type | name | usersMotto | Image | verifyMessage
    QVector<QByteArray> list = mysplit(recv);
    return {PersonalInfo(list[1],list[2],QByteArray::fromBase64(list[3])),list[4]};
}

PersonalInfo TCP::decode_friend_info(QByteArray recv)
{
    //type | name | usersMotto | Imag
    QVector<QByteArray> list = mysplit(recv);
    return PersonalInfo(list[1],list[2],QByteArray::fromBase64(list[3]));
}


#include<cstdio>
QByteArray TCP::bind(QByteArray array) {
    QString st(array);
    static char len[10];
    qDebug()<<array.size()<<endl;
    sprintf(len,"%06d",array.size());
    QString digital = QString(len);
    qDebug()<<digital<<endl;
    return (digital.toUtf8()+array);
}
