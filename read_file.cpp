#include "read_file.h"
#include <iostream>
#include <QtMqtt>
#include <fstream>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QTimerEvent>
#include <QTimer>
#include <QObject>
#include "comm_mqtt.h"

#define FILEGPIOFLAME "/sys/class/gpio/gpio26/value"

/**
 * @brief Construct a new My Timer:: My Timer object
 * 
 * @param parent 
 */
MyTimer::MyTimer(QWidget *parent)
{
    QString old_data;
    qDebug() << "Init Timer ";
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), this ,SLOT(timerEvent()));
    timer->start(100);
}

/**
 * @brief Action of timer: read gpio
 * 
 */
void MyTimer::timerEvent()
{
    QFile file(FILEGPIOFLAME);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream flux(&file);
        QString data_read = flux.readAll();
        file.close();
        data_read.replace("\n","");
        if(old_data != data_read)
        {
            qDebug() << "Data send: " << data_read;

            QString topic = TOPICFLAME;
            QJsonObject jobject;
            jobject["data"] = QString(data_read);

            emit DataToSend(topic, jobject);

            old_data = data_read;
        }

    }else{
        qDebug()<<"Impossible d'ouvrir le Fichier";
    }
}
