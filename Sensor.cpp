/*!
 * \file Sensor.cpp
 * \brief Make the connection beetween CommMqtt and ReceiveData
 * \author Thomas Abgrall
 * \version 0.1
 */

#include "Sensor.h"
#include "CommMqtt.h"
#include "ReceiveData.h"


/**
 * @brief Construct a new Inter Obj:: Inter Obj object
 * 
 * @param parent 
 */
Sensor::Sensor(QObject *parent) : QObject(parent)
{
    QList<QString>topicList {TOPICSUBSCRIB};
    m_read_file = new ReceiveData();
    m_comm = new CommMqtt("192.168.0.1", 1883, topicList);

    connect(m_read_file, &ReceiveData::DataToSend, m_comm, &CommMqtt::SendData);
}

/**
 * @brief Sensor::~Sensor
 */
Sensor::~Sensor()
{
    delete m_read_file;
    delete m_comm;
}
