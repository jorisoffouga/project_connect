#ifndef SENSOR_H
#define SENSOR_H

/*!
 * \file Sensor.h
 * \brief Make the connection beetween CommMqtt and ReceiveData
 * \author Thomas Abgrall
 * \version 0.1
 */

#include "CommMqtt.h"
#include "ReceiveData.h"

#define TOPICSUBSCRIB "/set/#"

/**
 * @brief The Sensor class
 */
class Sensor : public QObject
{
    Q_OBJECT
public:
    Sensor(QObject *parent = 0);
    ~Sensor();
private:
    /**
     * @brief m_read_file
     */
    ReceiveData *m_read_file;
    /**
     * @brief m_comm
     */
    CommMqtt *m_comm;
    /**
     * @brief m_MqttHandler
     */
    MqttHandler *m_MqttHandler;
};

#endif // SENSOR_H
