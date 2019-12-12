#ifndef MQTTHANDLER_H
#define MQTTHANDLER_H

#include <QObject>
#include <QtMqtt/QMqttClient>
#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QDebug>

class MqttHandler : public QObject
{
    Q_OBJECT
public:
    MqttHandler(QString &address, quint16 port, QList<QString> topicList);
    ~MqttHandler();
    QMqttClient *m_client;
    void publishData(QString &topic, QJsonObject &jsonData);
signals:

public slots:
    virtual void onMessage(QMqttMessage message);

private:
    void subscribe(QString topic);
    QString m_address;
    quint16 m_port;
    QList <QString> m_topic_list;
private slots:
    void clientStateChanged(QMqttClient::ClientState state);
};

#endif // MQTTHANDLER_H
