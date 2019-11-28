#include "airquality.h"

AirQuality::AirQuality()
{
    m_co2_val = 0;

    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &AirQuality::timerSlot);
    m_timer->start(1000);
}


quint16 AirQuality::readTvoc()
{
    QFile file("/sys/bus/iio/devices/iio\:device1/in_concentration_co2_raw");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Erreur d'ouverture";
        return 1;
    }

    QByteArray line = file.readLine();
    qDebug() << line;

    file.close();
    return 0;
}

void AirQuality::timerSlot()
{
    this->readTvoc();
}

// Fichier de lecture de CO2 : /sys/bus/iio/devices/iio\:device0/in_concentration_co2_raw
