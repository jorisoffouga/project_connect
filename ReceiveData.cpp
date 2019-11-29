#include "ReceiveData.h"
#include <QDebug>
#include <gpiod.hpp>

#define FILEGPIOFLAME "/sys/class/gpio/gpio26/value"

/**
 * @brief Construct a new My Timer:: My Timer object
 * 
 * @param parent 
 */
ReceiveData::ReceiveData(QWidget *parent)
{
    QString old_data;
    qDebug() << "Init Timer ";
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), this ,SLOT(timerEvent()));
    timer->start(100);
}


void ReceiveData::timerEvent()
{
    gpiod::chip  *chip = new gpiod::chip("0");

    gpiod::line line = chip->get_line(26);

    line.request({"SensorFire", gpiod::line_request::DIRECTION_INPUT, 0});
    m_data_read = line.get_value();
    line.release();

    if(m_old_data != m_data_read)
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
        emit DataToSend(topic, jobject);
        qDebug() << "Data send: " << jobject;

        m_old_data = m_data_read;
    }
}

//void ReceiveData::timerEvent()
//{
//    QFile file(FILEGPIOFLAME);
//    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        QTextStream flux(&file);
//        QString data_read = flux.readAll();
//        file.close();
//        data_read.replace("\n","");

//        if(m_old_data != m_data_read)
//        {
//            QString topic = TOPICFLAME;
//            QJsonObject jobject;
//            if(data_read == "0")
//            {
//                jobject["data"] = 0;
//            }
//            else
//            {
//                jobject["data"] = 1;
//            }
//            emit DataToSend(topic, jobject);
//            qDebug() << "Data send: " << jobject;

//            m_old_data = m_data_read;
//        }

//    }else{
//        qDebug()<<"Impossible d'ouvrir le Fichier";
//    }
//}

