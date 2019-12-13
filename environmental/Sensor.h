
#ifndef CLASS_MANAGER_H
#define CLASS_MANAGER_H

/*! \file Sensor.h
 * @author Eric Rebillon (eric.rebillon@ynov.com)
 * \brief A Document file.
   */

#include "MqttSensor.h"
#include "SensorValue.h"

#define TOPIC_TEMPERATURE   "/sensor/temperature"
#define TOPIC_HUMIDITY      "/sensor/humidity"
#define TOPIC_PRESSIURE     "/sensor/pressure"
#define TOPIC_ENVIRONMENT      "/sensor/environment"


/**
 * @brief The Sensor class
 * @brief connect the mqtt protocol and the data of sensor
 */
class Sensor : public QObject
{
    Q_OBJECT
public:
    Sensor();
    ~Sensor();
private:
    QList<QString> topicList;
    MqttSensor  *m_client;
    SensorValue *m_timer;

};

#endif // CLASS_MANAGER_H
