#ifndef MQTTHERIT_H
#define MQTTHERIT_H

#include <QObject>
#include "mqtthandler.h"

class MqttCom : public MqttHandler
{
    Q_OBJECT
public:
    MqttCom(QString address, quint16 port, QList<QString> topicList);

public slots:
    void onMessage(QMqttMessage message);
    void onMeasureSensor(QString topic, QJsonObject jsonData);


};
#endif // MQTTHERIT_H
