#ifndef COMMMQTT_H
#define COMMMQTT_H

/*!
 * \file CommMqtt.h
 * \brief Action of the Mqtt communication
 * \author Thomas Abgrall
 * \version 0.1
 */

#include "mqtthandler.h"
#include <gpiod.hpp>

#define TOPICFLAME "/sensor/flame"
#define TOPICGRAPH "/sensor/graph"
#define GPIO_CHIP_BARAGRAPH "2"

/**
 * @brief The CommMqtt class
 */
class CommMqtt: public MqttHandler
{
public:
    CommMqtt(QString address, quint16 port, QList<QString> topicList);

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
};

#endif // COMMMQTT_H
