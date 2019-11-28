#include "airquality.h"

AirQuality::AirQuality()
{
    m_payload["data_tvoc"] = "";
    m_payload["data_co2"] = "";
    m_payload["id"] = "42";
    m_topic = "";

    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &AirQuality::timerSlot);
    m_timer->start(5000);
}


void AirQuality::readTvoc()
{
    QFile file_tvoc("/sys/bus/iio/devices/iio\:device1/in_concentration_co2_raw");
    if (!file_tvoc.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Erreur d'ouverture tvoc. tentative avec un autre fichier";
    }

    QFile file_co2("/sys/bus/iio/devices/iio\:device1/in_concentration_co2_raw");
    if (!file_co2.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Erreur d'ouverture co2. tentative avec un autre fichier";
    }

    QString data_tvoc = file_tvoc.readLine();
    QString data_co2 = file_co2.readLine();

    file_tvoc.close();
    file_co2.close();

    qDebug() << "TVOC : " << data_tvoc << "\t co2 : " << data_co2 << ".";

    m_topic = "/sensor/air_quality";
    m_payload["data_tvoc"] = data_tvoc;
    m_payload["data_co2"] = data_co2;

    emit(onDataTvoc(m_topic, m_payload));
}

void AirQuality::timerSlot()
{
    this->readTvoc();
}

// Fichier de lecture de CO2 : /sys/bus/iio/devices/iio\:device0/in_concentration_co2_raw
