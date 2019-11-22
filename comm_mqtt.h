#ifndef COMM_MQTT_H
#define COMM_MQTT_H
#include <QList>
#include <QObject>
#include "mqtthandler.h"

class Comm_Mqtt: public MqttHandler
{

public:
    Comm_Mqtt(QString address, quint16 port, QList<QString> topicList);

public slots:
    void onMessage(QMqttMessage message) override;
    void SendData(QString &, QJsonObject &);

private:
    QString old_value;
    void treatment(QMqttMessage message);
    void verification();

};

#endif // COMM_MQTT_H
