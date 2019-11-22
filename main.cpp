#include <QCoreApplication>
#include "mqtthandler.h"
#include "gateway.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //    QString address = "localhost";
    QString address = "192.168.0.51";
    quint16 port = 1883;
    QList<QString> topicList;
    topicList.append("/sensor/tvoc");
    topicList.append("/sensor/co2");

    Gateway *mqtt = new Gateway(address, port, topicList);

    return a.exec();
}
