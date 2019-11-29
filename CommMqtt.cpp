#include "CommMqtt.h"
#include <gpiod.hpp>

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
    qDebug() << "topic:" << topic << "msg:" << msg;
    MqttHandler::publishData(topic,msg);
}

/**
 * @brief treatement of the message receive
 * 
 * @param message 
 */
void CommMqtt::onMessage(QMqttMessage message)
{
    //QString msgRecu = message.topic().name();

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
                if(valGrap < 9)
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
 * @param pin
 * @param value
 */
void CommMqtt::WriteGPIO(int pin, bool value)
{
    gpiod::chip  *chip = new gpiod::chip("2");
    gpiod::line line = chip->get_line(pin);

    line.request({"SensorFire", gpiod::line_request::DIRECTION_OUTPUT, 0});
    line.set_value(value);
    line.release();
}

