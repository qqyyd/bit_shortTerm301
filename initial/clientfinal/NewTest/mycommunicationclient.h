#ifndef MYCOMMUNICATIONCLIENT_H
#define MYCOMMUNICATIONCLIENT_H
#include<QObject>
#include"communication_client.h"
#include<QMap>

class myCommunicationClient : public QObject
{
    Q_OBJECT
public:
    explicit myCommunicationClient(QObject *parent = 0);
    static Communication_client *myClient;
    static QString my_id;

    static PersonalInfo myinfo;
    static QVector<PersonalInfo> allFriend;
    static PersonalInfo findInfo(QString id) {
        for (auto afriend : allFriend) {
            qDebug()<<"fri name "<<afriend.idNumber<<endl;
            if (afriend.idNumber == id) {
                return afriend;
            }
        }
        qDebug()<<"!!"<<id<<endl;
        throw "id not found";
    }
    static QVector<QPair<PersonalInfo,QString>> allRequest;

    static QVector<QPair<QString,QVector<QString>>> chat_recode;
    static QVector<QString> get_chat_recode(QString youfriend) {
        QVector<QString> list;
        for (auto recode : chat_recode) {
            if (recode.first == youfriend) {
                for (auto sentence : recode.second) {
                    list.push_back(sentence);
                }
            }
        }
        return list;
    }



signals:

public slots:
};

#endif // MYCOMMUNICATIONCLIENT_H
