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

MyTimer::MyTimer(QWidget *parent)
{
    //QMqttClient *client = new QMqttClient();
    QString old_data;
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), this ,SLOT(timerEvent()));
}

void MyTimer::timerEvent()
{
    QFile file("/home/thomas/Bureau/fichier_gpio");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream flux(&file);
        QString data_read = flux.readAll();
        file.close();
        if(old_data != data_read)
        {
            QString topic = "/feu";
            QJsonObject jobject;
            jobject["FireActive"] = QString(data_read);

            emit DataToSend(&topic, &jobject);

            old_data = data_read;
        }

    }else{
        qDebug()<<"Impossible d'ouvrir le Fichier";
    }
}
