#include "mqtthandler.h"

MqttHandler::MqttHandler(QString address, quint16 port, QList<QString> topicList):
    m_address(address), m_port(port), m_topic_list(topicList)
{
    m_client = new QMqttClient();
    connect(m_client, &QMqttClient::stateChanged, this, &MqttHandler::clientStateChanged);
    m_client->setHostname(m_address);
    m_client->setPort(m_port);
    m_client->connectToHost();
}


void MqttHandler::clientStateChanged(QMqttClient::ClientState state)
{
    switch (state) {

    case QMqttClient::Disconnected:
        qDebug() << "Client Disconnected";
        break;
    case QMqttClient::Connecting:
        qDebug() << "Client Connecting";
        break;
    case QMqttClient::Connected:
        qDebug() << "Client Connected";
        foreach(QString topic, m_topic_list){
            subscribe(topic);
        }
        break;
    }
}

void MqttHandler::subscribe(QString topic)
{
    QMqttTopicFilter topicFilter;
    topicFilter.setFilter(topic);

    QMqttSubscription *sub = m_client->subscribe(topicFilter, 0);

    if (sub)
    {
        qDebug() << "subscribe on " + topic;
        connect(sub, &QMqttSubscription::messageReceived, this, &MqttHandler::onMessage);
    }
    else
        qDebug() << "Error subscription on "<< topic;
}


void MqttHandler::onMessage(QMqttMessage message)
{
    qDebug() << "mqtt message receive from topic : " <<  message.topic().name() << " payload : " <<
                message.payload();
}
