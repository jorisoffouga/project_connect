#ifndef AIRQUALITY_H
#define AIRQUALITY_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QTimer>
#include <QJsonObject>


class AirQuality : public QObject
{
    Q_OBJECT
public:
    AirQuality();
    void readTvoc();
private:
    quint16 m_co2_val;
    QTimer *m_timer;
    QJsonObject m_payload;
    QString m_topic;


public slots :
    void timerSlot();

signals:
    void onDataTvoc(QString topic, QJsonObject payload);
};

#endif // AIRQUALITY_H
