/*! \file Sensor.cpp
 * \brief A Document file.
 * @author Eric Rebillon (eric.rebillon@ynov.com)

*/


#include "Sensor.h"
/**
 * @brief Sensor::Sensor
 * function collect the different class
 * declaration of both class for connect
 * call all the function for the sending
 * of data
 * @param parent
 */
Sensor::Sensor()
{
    topicList.append(TOPIC_TEMPERATURE);
    topicList.append(TOPIC_HUMIDITY);
    topicList.append(TOPIC_PRESSIURE);
    topicList.append(TOPIC_ENVIRONMENT);
    MqttSensor* m_client = new MqttSensor(ADRESS_IP, PORT, topicList);
    SensorValue* m_timer = new SensorValue();
    connect(m_timer, &SensorValue::dataChanged, m_client, &MqttSensor::dataPublish);

}

Sensor::~Sensor()
{
    delete m_timer;
    delete m_client;
}
