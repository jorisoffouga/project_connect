/*! \file SensorValue.cpp
 * \brief A Document file.
 * @author Eric Rebillon (eric.rebillon@ynov.com)
*/

#include "SensorValue.h"
/**
 * @brief SensorValue::SensorValue
 * function in interruption and called the function reading after a time define
 *
 */
SensorValue::SensorValue()
{
    QTimer *timer = new QTimer();
    /**
     * @brief QObject::connect
     * connect timer with the function who will be called
     */
    QObject::connect(timer, &QTimer::timeout, this , &SensorValue::dataSensor);
    timer->start(TMP_TIMER);
}

SensorValue::~SensorValue()
{}

/**
 * @brief SensorValue::dataSensor
 * read and convert data
 */
void SensorValue::dataSensor()
{
    QString data_temp;
    QString data_pression;
    QString data_humidity;
    QJsonObject jobject;

    /*! add topics who will be use for the data sending */
    topic.append(TOPIC_TEMPERATURE);
    topic.append(TOPIC_HUMIDITY);
    topic.append(TOPIC_PRESSIURE);
    topic.append(TOPIC_ENVIRONMENT);

    m_temperature = stringToValue(PATH_TEMPERATURE);
    m_temperature = (m_temperature/1000)-5;
    m_temperature = castValue(m_temperature,2);
    jobject["temperature"] = m_temperature;

    m_pressure = stringToValue(PATH_PRESSIURE);
    m_pressure = (m_pressure*10);
    m_pressure = castValue(m_pressure,0);
    jobject["pressure"] = m_pressure;

    m_humidity = stringToValue(PATH_HUMIDITY);
    m_humidity = (m_humidity/1024);
    m_humidity = castValue(m_humidity,0);
    jobject["humidity"] = m_humidity;
    send(jobject);
}

/**
 * @brief SensorValue::send
 * send data with mqtt protocol
 * the jobject of data sensor function will be send with this emit
 * @param data_sensor
 * contains the data which must be send
 *
 */
void SensorValue::send(QJsonObject dataSensor)
{
    emit dataChanged(topic.at(3), dataSensor);
}

/**
 * @brief SensorValue::stringtovalue
 * function of conversion and reading in file
 * the file contains the value of differents sensor
 * @param path
 * contains the path which will be open
 * @return
 * the value contains in the file but in double type
 */
double SensorValue::stringToValue(QString path)
{
    QString read;
    double value = 0;
    QFile file(path);
    QTextStream flux;

    flux.setDevice(&file);

    // add file and test before, if the file exist
    // else nothing , if the file exist , open and
    // take the value contains by the file and we return the value

    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly))
        {
            read = flux.readAll();
            read.replace("\n","");
            value = read.toDouble();
            file.close();
        }
    }
    return value;
}
/**
 * @brief SensorValue::cast_value
 * function allow choice the number after the comma
 * @param valeur
 * contains the value who will be convert
 * @param n
 * number de digits after the comma
 * @return
 * return the value with a cast
 *
 */
double SensorValue::castValue(double valeur, int n)
{
    double result=0;

    // we test the number of digits after comma
    //if the value is 0 we return a number with any digits after comma because the function
    // and if n is different of 0, so the function delete all the digits before comma except the disered one
    // to add readability when reading value

    if(n != 0)
    {
        n *= pow(10,n);
        double entier = (valeur * n);
        valeur =100* valeur;

        if(valeur -(entier >= 0.5))
            ++entier;

        result  = static_cast<double>(entier / n);

    }else{
        result = round(valeur);
    }

    return result;
}
