#ifndef MQTTHANDLER_H
#define MQTTHANDLER_H

#include <QObject>
#include <QtMqtt/QMqttClient>
#include <QString>
#include <QList>
#include <QDebug>

class MqttHandler : public QObject
{
    Q_OBJECT
public:
    explicit MqttHandler(QString address, quint16 port, QList<QString> topicList);

signals:

public slots:
    virtual void onMessage(QMqttMessage message);

private:
    void subscribe(QString topic);
    QMqttClient *m_client;
    QString m_address;
    quint16 m_port;
    QList <QString> m_topic_list;
private slots:
    void clientStateChanged(QMqttClient::ClientState state);
};

#endif // MQTTHANDLER_H
