#include "CommMqtt.h"

/**
 * @brief Construct a new CommMqtt::CommMqtt object
 * 
 * @param address 
 * @param port 
 * @param topicList 
 */
CommMqtt::CommMqtt(QString address, quint16 port, QList<QString> topicList):MqttHandler(address, port, topicList)
{
    address = "192.168.0.1";
    port = 1883;
    topicList.append(TOPICFLAME);
    topicList.append(TOPICGRAPH);
}

/**
 * @brief Call the method publish of MqttHandler to send data to the gateway
 * 
 * @param topic 
 * @param msg 
 */
void CommMqtt::SendData(QString topic, QJsonObject msg)
{
    MqttHandler::publishData(topic,msg);
}

/**
 * @brief treatement of the message receive
 * 
 * @param message 
 */
void CommMqtt::onMessage(QMqttMessage message)
{
    QString msgRecu = message.topic().name();

    qDebug() << "mqtt message receive from topic : " <<  message.topic().name() << " payload : " <<
                message.payload();

    int resu_comp = QString::compare(msgRecu,TOPICGRAPH);
    if (resu_comp == 0) {
        // recup num
        // affiche num
    }
    else {
        qDebug() << "a wrong topic was ask";
    }
}



