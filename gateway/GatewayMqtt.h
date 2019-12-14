#ifndef GATEWAY_MQTT_H
#define GATEWAY_MQTT_H

#include "MqttHandler.h"

#define MQTT_SENSOR_TOPIC "/sensor/#"
#define MQTT_GATEWAY_TOPIC "/gateway/#"

class GatewayMqtt : MqttHandler
{
    Q_OBJECT
public:
    GatewayMqtt(QString address, quint16 port, QList<QString> topicList);
    ~GatewayMqtt();

public slots:
    void onMessage(QMqttMessage message);

private:
};
#endif // GATEWAY_MQTT_H
