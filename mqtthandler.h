#ifndef MQTTHANDLER_H
#define MQTTHANDLER_H

/*!
 * \file CommMqtt.h
 * \brief
 * \author
 * \version 0.1
 */

#include <QObject>
#include <QtMqtt/QMqttClient>
#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QDebug>

/**
 * @brief The MqttHandler class
 */
class MqttHandler : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief MqttHandler
     * @param address
     * @param port
     * @param topicList
     */
    MqttHandler(QString &address, quint16 port, QList<QString> topicList);
    ~MqttHandler();
    /**
     * @brief m_client
     */
    QMqttClient *m_client;
    /**
     * @brief publishData
     * @param topic
     * @param jsonData
     */
    void publishData(QString &topic, QJsonObject &jsonData);
signals:

public slots:
    /**
     * @brief onMessage
     * @param message
     */
    virtual void onMessage(QMqttMessage message);

private:
    /**
     * @brief subscribe
     * @param topic
     */
    void subscribe(QString topic);
    /**
     * @brief m_address
     */
    QString m_address;
    /**
     * @brief m_port
     */
    quint16 m_port;
    /**
     * @brief m_topic_list
     */
    QList <QString> m_topic_list;
private slots:
    /**
     * @brief clientStateChanged
     * @param state
     */
    void clientStateChanged(QMqttClient::ClientState state);
};

#endif // MQTTHANDLER_H
