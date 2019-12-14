/*!
 * \file ReceiveData.cpp
 * \brief Manage data receive
 * \author Thomas Abgrall
 * \version 0.1
 */

#include "SensorGpioData.h"


/**
 * @brief SensorGpioData::SensorGpioData
 */
SensorGpioData::SensorGpioData()
{
    QTimer *m_timer = new QTimer();
    QObject::connect(m_timer, &QTimer::timeout, this, &SensorGpioData::gpioEvent);
    m_chip = new gpiod::chip(GPIO_CHIP_FLAME); /** object gpio chip */
    m_timer->start(100);
}

/**
 * @brief SensorGpioData::~SensorGpioData
 */
SensorGpioData::~SensorGpioData()
{
    delete m_chip;

    if(m_timer->isActive())
        m_timer->stop();

    delete m_timer;
}

/**
 * @brief SensorGpioData::GpioEvent
 * This function are call when the timer is over, it take the bool flame pin value and send it.
 */
void SensorGpioData::gpioEvent()
{
    static int oldData = 0;
    gpiod::line line = m_chip->get_line(26);
    line.request({"SensorFire", gpiod::line_request::DIRECTION_INPUT, 0});
    m_data_read = line.get_value();
    line.release();

    if(oldData != m_data_read)
    {
        QString topic = TOPICFLAME;
        QJsonObject jobject;
        if(m_data_read == 0)
        {
            jobject["data"] = 0;
        }
        else
        {
            jobject["data"] = 1;
        }
        emit dataGpioReady(topic, jobject);
        oldData = m_data_read;
    }
}
