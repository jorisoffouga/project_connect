/*!
 * \file Sensor.cpp
 * \brief Make the connection beetween CommMqtt and ReceiveData
 * \author Thomas Abgrall
 * \version 0.1
 */

#include "Sensor.h"
#include <QDebug>

/**
 * @brief Construct a new Inter Obj:: Inter Obj object
 * this function make the connection beetween Receivedata and CommMqtt.
 * @param parent 
 */
Sensor::Sensor(QString address, quint16 port, QList<QString> topicList) : MqttHandler(address, port, topicList)
{
    m_chip = new gpiod::chip(GPIO_CHIP_BARAGRAPH); /** object gpio chip */
    m_sensorGpio = new SensorGpioData();

    connect(m_sensorGpio, &SensorGpioData::DataGpioReady, this, &Sensor::SendData);
}

/**
 * @brief Sensor::~Sensor
 */
Sensor::~Sensor()
{
    delete m_sensorGpio;
    delete m_chip;
}

/**
 * @brief Sensor::SendData
 * Call the method publish of MqttHandler to send data to the gateway
 * @param topic
 * name of the topic where we want to send message
 * @param msg
 * data to send, in QJsonObject
 */
void Sensor::SendData(QString topic, QJsonObject msg)
{
    qDebug() <<"topic: " << topic << "msg :"<< msg;
    publishData(topic, msg);
}

/**
 * @brief Sensor::onMessage
 * treatement of the message receive
 * @param message
 * data receive from a pc
 */
void Sensor::onMessage(QMqttMessage message)
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

    int valGrap = 0;

    if(topic_origin == "set"){
        if(topic_destination == "graph"){
            if(payload.contains("graph"))
            {
                valGrap = payload.value("graph").toInt();
                if(0 < valGrap && valGrap< 10)
                {
                    for (int i=0;i<valGrap;i++)
                    {
                        WriteGPIO(i,0);
                    }
                    for (int i=valGrap;i<10;i++) {
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
 * @brief Sensor::WriteGPIO
 * Set a specific gpio in OUTPUT and set a value inside
 * @param pin
 * num of the pin
 * @param value
 * value to set in the gpio
 */
void Sensor::WriteGPIO(int pin, bool value)
{
    gpiod::line line = m_chip->get_line(pin);

    line.request({"SensorFire", gpiod::line_request::DIRECTION_OUTPUT, value});
    line.release();
}
