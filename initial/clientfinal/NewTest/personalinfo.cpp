#include "personalinfo.h"

PersonalInfo::PersonalInfo()
{

}
#include<string>
#include<iostream>
PersonalInfo::PersonalInfo(QString idNumber, QString usersMotto, QByteArray image)
    : idNumber(idNumber),usersMotto(usersMotto)
{
//    std::cerr<<"?? "<<image.toBase64().toStdString()<<" ?"<<endl;
    qDebug()<<"idnb "<<idNumber<<endl;
//    for (auto x : image) qDebug()<<x;
    qDebug()<<"build ig "<<this->image.loadFromData(image)<<endl;
    this->image.save("D:\\20220817-qt\\clientfinal\\NewTest\\1.png");
}
