/*!
 * \file CommMqtt.cpp
 * \brief Action of the Mqtt communication
 * \author Thomas Abgrall
 * \version 0.1
 */

#include "CommMqtt.h"


/**
 * @brief CommMqtt::CommMqtt
 * Construct
 * @param address
 * 192.168.0.1
 * @param port
 * 1883
 * @param topicList
 * Constructor of the class
 */

CommMqtt::CommMqtt(QString address, quint16 port, QList<QString> topicList):MqttHandler(address, port, topicList)
{
    address = "192.168.0.1";
    port = 1883;
    topicList.append(TOPICFLAME);
    topicList.append(TOPICGRAPH);
    m_chip = new gpiod::chip(GPIO_CHIP_BARAGRAPH);
}

/**
 * @brief CommMqtt::SendData
 * Call the method publish of MqttHandler to send data to the gateway
 * @param topic
 * name of the topic where we want to send message
 * @param msg
 * data to send, in QJsonObject
 */
void CommMqtt::SendData(QString topic, QJsonObject msg)
{
    MqttHandler::publishData(topic,msg);
}

/**
 * @brief CommMqtt::onMessage
 * treatement of the message receive
 * @param message
 * data receive from a pc
 */
void CommMqtt::onMessage(QMqttMessage message)
{
    qDebug() << "mqtt message receive from topic : " <<  message.topic().name() << " payload : " <<
                message.payload();

    QStringList topic_parsed = message.topic().name().split('/');
    QString topic_origin = topic_parsed[1];
    QString topic_destination = topic_parsed[2];

    QString new_topic = "Error";

    QJsonDocument dataJSON = QJsonDocument::fromJson(message.payload());
    QJsonObject payload = dataJSON.object();
    QJsonObject tempObject;

    int valGrap;

    if(topic_origin == "set"){
        if(topic_destination == "graph"){
            if(payload.contains("graph"))
            {
                valGrap = payload.value("graph").toInt();
                if(0 < valGrap < 9)
                {
                    for (int i=0;i<valGrap;i++)
                    {
                        WriteGPIO(i,0);
                    }
                    for (int i=valGrap;i<9;i++) {
                        WriteGPIO(i,1);
                    }
                }
                else {
                    qDebug()<<"WARNING Data receive:"<<valGrap<<"is over 9";
                }
            }
            qDebug() << "Graph :" << valGrap;
        }
    }
}

/**
 * @brief CommMqtt::WriteGPIO
 * Set a specific gpio in OUTPUT and set a value inside
 * @param pin
 * num of the pin
 * @param value
 * value to set in the gpio
 */
void CommMqtt::WriteGPIO(int pin, bool value)
{
    gpiod::line line = m_chip->get_line(pin);

    line.request({"SensorFire", gpiod::line_request::DIRECTION_OUTPUT, value});
    line.release();
}
