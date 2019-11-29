#ifndef ReceiveData_H
#define ReceiveData_H

/*!
 * \file ReceiveData.h
 * \brief Manage data receive
 * \author Thomas Abgrall
 * \version 0.1
 */

#include <QFile>
#include <QTextStream>
#include <QTimer>
#include "CommMqtt.h"

/**
 * @brief The ReceiveData class
 */
class ReceiveData : public QObject
{
    Q_OBJECT
public:
    ReceiveData(QWidget *parent=0);
    /**
     * @brief timer
     * timer who execut the reading of the GPIO
     */
    QTimer* timer;
    /**
     * @brief m_data_read
     * bool(0 or 1) data read from the GPIO
     */
    int m_data_read;
    /**
     * @brief m_old_data
     * the olf data read
     */
    int m_old_data;

public slots:
    void timerEvent();

private:

signals:
    void DataToSend(QString, QJsonObject);
};

#endif // ReceiveData_H
