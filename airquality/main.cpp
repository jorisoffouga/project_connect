#include <QCoreApplication>
#include "mqttcom.h"
#include "airquality.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Paramétrage de la connection MQTT
    //    QString address = "localhost";
    QString address = "192.168.0.1";
    quint16 port = 1883;
    QList<QString> topicList;
    topicList.append("/command/tvoc");
    topicList.append("/command/co2");

    MqttCom *mqtt = new MqttCom(address, port, topicList);

    AirQuality *sensor = new AirQuality();

    // Connection entre le signal et le slot pour envoyer les données depuis le capteurs vers le publish MQTT
    QObject::connect(sensor, &AirQuality::onDataSensor, mqtt, &MqttCom::onMeasureSensor);

    return a.exec();
}
