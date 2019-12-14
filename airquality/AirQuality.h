#ifndef AIRQUALITY_H
#define AIRQUALITY_H

#include <QFile>
#include <QTimer>
#include "AirQualityMqtt.h"

#define TVOCPATHDEV0 "/sys/bus/iio/devices/iio\:device0/in_concentration_voc_raw"
#define TVOCPATHDEV1 "/sys/bus/iio/devices/iio\:device1/in_concentration_voc_raw"

#define CO2PATHDEV0 "/sys/bus/iio/devices/iio\:device0/in_concentration_co2_raw"
#define CO2PATHDEV1 "/sys/bus/iio/devices/iio\:device1/in_concentration_co2_raw"

#define AIRQUALITYTOPIC "/sensor/air_quality"

class AirQuality : public QObject
{
    Q_OBJECT
public:
    AirQuality();

    QString readCo2();
    QString readTvoc();

private:
    QTimer *m_timer;
    AirQualityMqtt *m_mqtt;

public slots :
    void readSensor();
    void timerSlot();

signals:
    void onDataSensor(QString topic, QJsonObject payload);
};

#endif // AIRQUALITY_H
