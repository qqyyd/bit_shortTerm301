#include "mycommunicationclient.h"


Communication_client * myCommunicationClient::myClient;
QString myCommunicationClient::my_id;

PersonalInfo myCommunicationClient::myinfo;
QVector<PersonalInfo> myCommunicationClient::allFriend;
QVector<QPair<PersonalInfo,QString>> myCommunicationClient::allRequest;

QVector<QPair<QString,QVector<QString>>> myCommunicationClient::chat_recode;


myCommunicationClient::myCommunicationClient(QObject *parent) : QObject(parent)
{

}
