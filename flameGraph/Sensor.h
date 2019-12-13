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

class Sensor : public MqttHandler
{
public:
    Sensor(QString address, quint16 port, QList<QString> topicList);
    ~Sensor();

public slots:
    void onMessage(QMqttMessage message) override;
    void SendData(QString, QJsonObject);

private:
    QString old_value;
    void WriteGPIO(int, bool);
    gpiod::chip  *m_chip;
    SensorGpioData *m_sensorGpio;
    MqttHandler *m_MqttHandler;

};

#endif // SENSOR_H
