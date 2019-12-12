#ifndef SENSOR_H
#define SENSOR_H

/*!
 * \file Sensor.h
 * \brief Make the connection beetween CommMqtt and ReceiveData
 * \author Thomas Abgrall
 * \version 0.1
 */

#include "SensorGpioData.h"
#include "mqtthandler.h"

#define TOPICSUBSCRIB "/set/#"
#define TOPICFLAME "/sensor/flame"
#define TOPICGRAPH "/sensor/graph"
#define ADRESS "192.168.0.1"  /**local adress */
#define PORT 1883             /**local port */
#define GPIO_CHIP_BARAGRAPH "2"

/**
 * @brief The Sensor class
 */
class Sensor : public MqttHandler
{
public:
    Sensor(QString address, quint16 port, QList<QString> topicList);
    ~Sensor();

public slots:
    void onMessage(QMqttMessage message) override;
    /**
     * @brief SendData
     */
    void SendData(QString, QJsonObject);

private:
    /**
     * @brief old_value
     */
    QString old_value;
    /**
     * @brief WriteGPIO
     */
    void WriteGPIO(int, bool);
    /**
     * @brief m_chip
     */
    gpiod::chip  *m_chip;
    /**
     * @brief m_read_file
     */
    SensorGpioData *m_sensorGpio;
    /**
     * @brief m_MqttHandler
     */
    MqttHandler *m_MqttHandler;

};

#endif // SENSOR_H
