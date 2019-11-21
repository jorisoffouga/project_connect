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

class MqttHerit : MqttHandler
{
    Q_OBJECT
public:
    MqttHerit(QString address, quint16 port, QList<QString> topicList);

public slots:
    void onMessage(QMqttMessage message);
};
#endif // MQTTHERIT_H
