#ifndef MQTTHERIT_H
#define MQTTHERIT_H

#include "mqtthandler.h"

#define MQTT_SENSOR_TOPIC "/sensor/#"
#define MQTT_GATEWAY_TOPIC "/gateway/#"

class Gateway : MqttHandler
{
    Q_OBJECT
public:
    Gateway(QString address, quint16 port, QList<QString> topicList);
    ~Gateway();

public slots:
    void onMessage(QMqttMessage message);

private:
};
#endif // MQTTHERIT_H
