#ifndef SensorGpioData_H
#define SensorGpioData_H

/*!
 * \file ReceiveData.h
 * \brief Manage data receive
 * \author Thomas Abgrall
 * \version 0.1
 */

#include <QTimer>
#include <QJsonObject>
#include <QDebug>
#include <gpiod.hpp>

#define TOPICFLAME "/sensor/flame"
#define GPIO_CHIP_FLAME "0"

/**
 * @brief The ReceiveData class
 */
class SensorGpioData : public QObject
{
    Q_OBJECT
public:
    SensorGpioData();
    ~SensorGpioData();

public slots:

    void GpioEvent();

private:
    /**
     * @brief timer
     * timer who execut the reading of the GPIO
     */
    QTimer* m_timer;
    /**
     * @brief m_data_read
     * bool(0 or 1) data read from the GPIO
     */
    int m_data_read;
    /**c
     * @brief m_chip
     */
    gpiod::chip  *m_chip;
signals:
    void DataGpioReady(QString, QJsonObject);
};

#endif // SensorGpioData_H
