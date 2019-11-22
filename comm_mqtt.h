/*! \file structcmd.h
    \brief A Documented file.

    Details.
*/

#ifndef COMM_MQTT_H
#define COMM_MQTT_H
#include <QList>
#include <QObject>
#include "mqtthandler.h"

#define TOPICFLAME "/sensor/flame"
#define TOPICGRAPH "/sensor/graph"

class Comm_Mqtt: public MqttHandler
{
public:
    Comm_Mqtt(QString address, quint16 port, QList<QString> topicList);

public slots:
    void onMessage(QMqttMessage message) override;
    void SendData(QString, QJsonObject);

private:
    QString old_value;
};

#endif // COMM_MQTT_H
