#ifndef TCP_H
#define TCP_H

#include <QObject>
#include "personalinfo.h"
#include <QString>
#include <QPair>
#include <QVector>

class TCP : public QObject
{
    Q_OBJECT
public:
    explicit TCP(QObject *parent = nullptr);
    static QString separator;
    static QString end;
    static QByteArray bend;

    static QString encode_send_string_message(QString message, QString from, QString to);
    static QString encode_login_register(QString type, QString idNumber, QString password);
    static QString encode_find_friend(QString, QString);
    static QString encode_add_friend(QString, QString, QString);
    static QString encode_deal_new_friend(QString, QString, QString);
    static QString encode_change_image();
    static QString encode_change_usersMotto(QString);

    static QString decode_head(QByteArray recv) ;
    static QVector<QString> decode_string_message(QString recv);
    static QVector<PersonalInfo> decode_initial_friend_list(QByteArray recv) ;
    static QVector<QPair<QString,QVector<QString>>> decode_initial_chat_recode(QString recv);
    static QVector<QPair<PersonalInfo,QString>> decode_initial_request_recode(QByteArray recv);

    static QString decode_friend_add_try(QString);
    static QPair<PersonalInfo,QString> decode_friend_request_info(QByteArray);
    static PersonalInfo decode_friend_info(QByteArray);

    static QByteArray bind(QByteArray);
signals:

public slots:
};

#endif // TCP_H
