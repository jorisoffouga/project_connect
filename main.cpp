#include <QCoreApplication>
#include "mqtthandler.h"
#include "mqttherit.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QString address = "192.168.0.51";
    QString address = "localhost";
    quint16 port = 1883;
    QList<QString> topicList;
    topicList.append("/stuff");
    topicList.append("/test");

    MqttHerit *mqtt = new MqttHerit(address, port, topicList);

    return a.exec();
}
