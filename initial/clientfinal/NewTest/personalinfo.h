#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include <QImage>
#include <QString>
#include<QDebug>
class PersonalInfo
{
public:
    QString idNumber;
    QString usersMotto;
    QImage image;


    PersonalInfo();
    PersonalInfo(QString, QString, QByteArray);
};

#endif // PERSONALINFO_H
