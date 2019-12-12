#ifndef AIRQUALITY_H
#define AIRQUALITY_H


#define tvocPath_dev0 "/sys/bus/iio/devices/iio\:device0/in_concentration_voc_raw"
#define tvocPath_dev1 "/sys/bus/iio/devices/iio\:device1/in_concentration_voc_raw"

#define co2Path_dev0 "/sys/bus/iio/devices/iio\:device0/in_concentration_co2_raw"
#define co2Path_dev1 "/sys/bus/iio/devices/iio\:device1/in_concentration_co2_raw"

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <QJsonObject>


class AirQuality : public QObject
{
    Q_OBJECT
public:
    AirQuality();

    QString readCo2();
    QString readTvoc();

private:
    quint16 m_co2_val;
    QTimer *m_timer;
    QJsonObject m_payload;
    QString m_topic;
    QString m_co2;
    QString m_tvoc;

public slots :
    void readSensor();
    void timerSlot();

signals:
    void onDataSensor(QString topic, QJsonObject payload);
};

#endif // AIRQUALITY_H
