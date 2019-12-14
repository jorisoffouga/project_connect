#include <QCoreApplication>
#include "GatewayMqtt.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GatewayMqtt *mqtt = new GatewayMqtt(MQTT_ADDR, MQTT_PORT, {MQTT_SENSOR_TOPIC, MQTT_GATEWAY_TOPIC});
    Q_UNUSED(mqtt)

    return a.exec();
}
