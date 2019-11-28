#ifndef MQTTHERIT_H
#define MQTTHERIT_H

#include <QObject>
#include <QtMqtt/QMqttClient>
#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QDebug>
#include "mqtthandler.h"

#define MQTT_ADDR "192.168.0.1"
#define MQTT_PORT 1883
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
