#include "comm_mqtt.h"
#include "mqtthandler.h"
#include <QString>


/**
 * @brief Construct a new Comm_Mqtt::Comm_Mqtt object
 * 
 * @param address 
 * @param port 
 * @param topicList 
 */
Comm_Mqtt::Comm_Mqtt(QString address, quint16 port, QList<QString> topicList):MqttHandler(address, port, topicList)
{
    address = "localhost";
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
void Comm_Mqtt::SendData(QString topic, QJsonObject msg)
{
    MqttHandler::publishData(topic,msg);
}

/**
 * @brief treatement of the message receive
 * 
 * @param message 
 */
void Comm_Mqtt::onMessage(QMqttMessage message)
{
    QString msgRecu = message.topic().name();

    qDebug() << "mqtt message receive fils from topic : " <<  message.topic().name() << " payload : " <<
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



