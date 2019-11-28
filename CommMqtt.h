/*! \file structcmd.h
    \brief A Documented file.

    Details.
*/

#ifndef COMMMQTT_H
#define COMMMQTT_H
#include "mqtthandler.h"

#define TOPICFLAME "/sensor/flame"
#define TOPICGRAPH "/sensor/graph"

class CommMqtt: public MqttHandler
{
public:
    CommMqtt(QString address, quint16 port, QList<QString> topicList);

public slots:
    void onMessage(QMqttMessage message) override;
    void SendData(QString, QJsonObject);

private:
    QString old_value;
};

#endif // COMMMQTT_H
