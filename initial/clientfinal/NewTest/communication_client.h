#ifndef COMMUNICATION_CLIENT_H
#define COMMUNICATION_CLIENT_H

#include <QString>
#include <QDebug>
#include <QHostAddress>
#include <QTcpSocket>
#include <QVector>
#include <QImage>
#include "tcp.h"
#include "personalinfo.h"
#include <QPixmap>
#include <QBuffer>
#include<QThread>
#include "reader.h"
#define DEBUG
class Communication_client : public QObject{
    Q_OBJECT
public:
    explicit Communication_client(QObject *parent = nullptr);

    QString ip;
    int port;
    QTcpSocket *client = NULL;

    QString newest_string_message_id;
    QString newest_string_message;

    QVector<PersonalInfo> friendList;

    bool try_connection(QString ip="127.0.0.1", int port=8889);//give ip and port

    bool try_to_register(QString, QString);
    bool try_to_login(QString, QString);
    bool send_string_message(QString st, QString a, QString b); //use this to send a string from a to b
    bool find_friend(QString from, QString to);
    bool add_friend(QString v, QString a, QString b); //try to add a friend with id b by a, v is verify message
    bool change_head_image(QImage image);
    bool change_userMotto(QString newMotto);

    bool friend_accept(QString opter, QString original); //opter accpet the request from ori
    bool friend_reject(QString opter, QString original); //opter reject the request from ori

    void get_string_message(QByteArray); //
    void get_initial_friend_list(QByteArray);
    void get_find_friend_result(QByteArray);
    void get_new_friend_add_request(QByteArray);
    void get_new_friend(QByteArray);
    void get_rejected_friend_info(QByteArray);
    void get_initial_chat_recode(QByteArray);
    void get_initial_request_recode(QByteArray);

#ifdef DEBUG
    void write(QString message) {
        client->write(message.toUtf8());
    }
#endif
signals:
    void new_string_message_ready(QString, QString);
    void friendList_ready(QVector<PersonalInfo>);
    void request_recode_ready(QVector<QPair<PersonalInfo,QString>>);
    void chat_recode_ready(QVector<QPair<QString,QVector<QString>>>);
    void login_feedback(int);
    void register_feedback(int);
    void find_friend_result(QString);
    void friend_request(PersonalInfo,QString);
    void new_friend_added(PersonalInfo);
    void be_rejected(PersonalInfo);
    void head_image_change_state(int);
    void usersMotto_change_state(int);
};

#endif // COMMUNICATION_CLIENT_H


