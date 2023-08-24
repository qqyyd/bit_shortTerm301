#include "widget.h"
#include "communication_client.h"
#include "mycommunicationclient.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString ip = "127.0.0.1";
//    QString ip = "192.168.162.133";
    int port = 8889;
    myCommunicationClient::myClient = new Communication_client();
    qDebug()<<"client connect: "<<myCommunicationClient::myClient->try_connection(ip,port);//connect to the server
    Widget w;
    QDesktopWidget *pDesk = QApplication::desktop();
    w.move((pDesk->width() - w.width()) / 2,(pDesk->height() - w.height()) / 2);
    w.show();
    return a.exec();
}
