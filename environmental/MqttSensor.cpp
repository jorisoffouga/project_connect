/*! \file MqttSensor.cpp
 * @author Eric Rebillon (eric.rebillon@ynov.com)
 * \brief A Document file.
*/

#include "MqttSensor.h"

/**
 * @brief MqttSensor::MqttSensor
 * @param address
 * address ip of gateway
 * @param port
 * mqtt port
 * @param topicList
 * all topics using by the mqtt protocol
 */
MqttSensor::MqttSensor(QString address, quint16 port, QList<QString> topicList):MqttHandler(address, port, topicList)
{

}

MqttSensor::~MqttSensor(){}

/**
 * @brief MqttSensor::data_publish
 * @param Topic
 * @param data
 * function transmit data via mqtt protocol
 */
void MqttSensor::dataPublish(QString Topic, QJsonObject data)
{
    MqttHandler::publishData(Topic,data);
}

/**
 * @brief MqttSensor::onMessage
 * @param message
 * Function receiving data via mqtt protocol
 */
void MqttSensor::onMessage(QMqttMessage message){
        qDebug() <<  message.topic().name()<<message.payload();

}
