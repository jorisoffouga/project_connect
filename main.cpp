#include <QCoreApplication>
#include "mqtthandler.h"
#include "gateway.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Gateway *mqtt = new Gateway(MQTT_ADDR, MQTT_PORT, {MQTT_SENSOR_TOPIC, MQTT_GATEWAY_TOPIC});
    Q_UNUSED(mqtt)

    return a.exec();
}
