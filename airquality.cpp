#include "airquality.h"

AirQuality::AirQuality()
{
    m_payload["data_tvoc"] = "";
    m_payload["data_co2"] = "";
    m_payload["id"] = "42";
//    m_payload["6 * 7"] = "42";
//    m_payload["La reponse a la grande question sur la vie, l'univers et le reste"] = "42";
    m_topic = "";

    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &AirQuality::timerSlot);
    m_timer->start(5000);
}


void AirQuality::readSensor()
{
    QFile file_tvoc("/sys/bus/iio/devices/iio\:device1/in_concentration_voc_raw");
    if (!file_tvoc.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Erreur d'ouverture tvoc. tentative avec un autre fichier";
    }

    QFile file_co2("/sys/bus/iio/devices/iio\:device1/in_concentration_co2_raw");
    if (!file_co2.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Erreur d'ouverture co2. tentative avec un autre fichier";
    }

    QString data_tvoc = file_tvoc.readLine().split('\n')[0];
    QString data_co2 = file_co2.readLine().split('\n')[0];

    file_tvoc.close();
    file_co2.close();

    qDebug() << "TVOC : " << data_tvoc << "\t CO2 : " << data_co2 << ".";

    m_topic = "/sensor/air_quality";
    m_payload["data_tvoc"] = data_tvoc;
    m_payload["data_co2"] = data_co2;

    emit(onDataSensor(m_topic, m_payload));
}

void AirQuality::timerSlot()
{
    this->readSensor();
}

// Fichier de lecture de CO2 : /sys/bus/iio/devices/iio\:device0/in_concentration_co2_raw
