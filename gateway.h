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

class Gateway : MqttHandler
{
    Q_OBJECT
public:
    Gateway(QString address, quint16 port, QList<QString> topicList);

public slots:
    void onMessage(QMqttMessage message);

private:

};
#endif // MQTTHERIT_H
