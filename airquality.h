#ifndef AIRQUALITY_H
#define AIRQUALITY_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QTimer>


class AirQuality : public QObject
{
    Q_OBJECT
public:
    AirQuality();
    quint16 readTvoc();
private:
    quint16 m_co2_val;
    QTimer *m_timer;

public slots :
    void timerSlot();
};

#endif // AIRQUALITY_H
