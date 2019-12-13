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
    MqttSensor* m_client = new MqttSensor(MQTT_ADDR, MQTT_PORT, {TOPIC_TEMPERATURE,
                                          TOPIC_HUMIDITY, TOPIC_PRESSIURE, TOPIC_ENVIRONMENT});
    SensorValue* m_timer = new SensorValue();
    connect(m_timer, &SensorValue::dataChanged, m_client, &MqttSensor::dataPublish);

}

Sensor::~Sensor()
{
    delete m_timer;
    delete m_client;
}
