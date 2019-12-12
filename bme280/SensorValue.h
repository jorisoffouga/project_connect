
#ifndef TRAITEMENT_FICHIER_H
#define TRAITEMENT_FICHIER_H

/*! \file SensorValue.h
 * @author Eric Rebillon (eric.rebillon@ynov.com)
 * \brief A Document file.
*/

#define PATH_TEMPERATURE    "/sys/bus/iio/devices/iio\:device0/in_temp_input"
#define PATH_PRESSIURE      "/sys/bus/iio/devices/iio\:device0/in_pressure_input"
#define PATH_HUMIDITY       "/sys/bus/iio/devices/iio\:device0/in_humidityrelative_input"
#define PATH_TEST           "/home/eric/Master1/workspace/Cpp_project_archi_logicielle/fichier_sim_bme_280.txt"

#define TOPIC_TEMPERATURE   "/sensor/temperature"
#define TOPIC_HUMIDITY      "/sensor/humidity"
#define TOPIC_PRESSIURE     "/sensor/pressure"
#define TOPIC_ENVIRONMENT      "/sensor/environment"

#define TMP_TIMER   3000

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QEvent>
#include <QTimer>
#include <QList>
#include <QDebug>
#include <QJsonObject>
#include <QtMath>


/**
 * @brief The SensorValue class
 * @brief set up the reading and emit the data to mqtt protocol
 */
class SensorValue : public QObject
{
    Q_OBJECT
public:
    SensorValue();
    ~SensorValue();
    QFile file ;
    QTextStream flux;
    QTimer* timer;

public slots:
    void dataSensor();
    void send(QJsonObject);
    double stringToValue(QString);
    double castValue(double, int);

signals:
    void dataChanged(QString, QJsonObject);
private:
    QList <QString> topic;

    double m_temperature = 0;
    double m_pressure = 0;
    double m_humidity = 0;

};

#endif // TRAITEMENT_FICHIER_H
