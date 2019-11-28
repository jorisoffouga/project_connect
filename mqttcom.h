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

class MqttCom : MqttHandler
{
    Q_OBJECT
public:
    MqttCom(QString address, quint16 port, QList<QString> topicList);

public slots:
    void onMessage(QMqttMessage message);
    void onMeasureTvoc(QString &topic, QJsonObject &jsonData);
//    void onMeasureCo2(quint16 co2_val);


};
#endif // MQTTHERIT_H
