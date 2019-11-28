#include <QCoreApplication>
#include "mqtthandler.h"
#include "mqttcom.h"
#include "airquality.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //    QString address = "localhost";
    QString address = "192.168.0.1";
    quint16 port = 1883;
    QList<QString> topicList;
    topicList.append("/command/tvoc");
    topicList.append("/command/co2");

    MqttCom *mqtt = new MqttCom(address, port, topicList);

    AirQuality *sensor = new AirQuality();


    sensor->readTvoc();

    return a.exec();
}
