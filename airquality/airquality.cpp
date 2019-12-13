#include "airquality.h"
#include "QThread"

AirQuality::AirQuality()
{
    // Initialisation des json et variables du publish MQTT
    m_payload["data_tvoc"] = "";
    m_payload["data_co2"] = "";
    m_payload["id"] = "42";
    m_topic = "/sensor/air_quality";

    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &AirQuality::readSensor);
    m_timer->start(5000);
}

QString AirQuality::readCo2()
{
    QString read;
    QFile file(CO2PATHDEV1);
    QTextStream flux;
    long data = 0;

    // add file and test before, if the file exist
    // else nothing , if the file exist , open and
    // take the value contains by the file and we return the value

    flux.setDevice(&file);
    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly))
        {
            read = flux.readAll();
            read.replace("\n","");
            data = read.toLong();
            file.close();
        }
    }
    else{
        file.setFileName(CO2PATHDEV0);

        // add file and test before, if the file exist
        // else nothing , if the file exist , open and
        // take the value contains by the file and we return the value

        flux.setDevice(&file);
        if(file.exists())
        {
            if(file.open(QIODevice::ReadOnly))
            {
                read = flux.readAll();
                read.replace("\n","");
                data = read.toLong();
                file.close();
            }
        }
    }

    if(data < 400 || data > 8192)
        read = "Error";

    qDebug() << "Co2 :" << data << " " << read;
    return read;
}

QString AirQuality::readTvoc()
{
    QString read;
    QFile file(TVOCPATHDEV1);
    QTextStream flux;
    long data = 0;
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
            data = read.toLong();
            file.close();
        }
    }
    else{
        file.setFileName(TVOCPATHDEV0);
        flux.setDevice(&file);

        if(file.exists())
        {
            if(file.open(QIODevice::ReadOnly))
            {
                read = flux.readAll();
                read.replace("\n","");
                data = read.toLong();
                file.close();
            }
        }
    }

    if(read == "" || data > 1187)
        read = "Error";

    qDebug() << "TVOC: " << data << " " << read;
    return read;
}


void AirQuality::readSensor()
{
    QJsonObject jobject;

    m_co2 = readCo2();
    QThread::msleep(300);
    m_tvoc = readTvoc();

    // Ajout des données relevées au payload JSON
    if(m_co2 != "Error" && m_tvoc != "Error"){
        jobject["data_co2"] = m_co2;
        jobject["data_tvoc"] = m_tvoc;
        emit onDataSensor(m_topic, jobject);
    }
}

void AirQuality::timerSlot()
{
    // Appel de la fonction readSensor à chaque intervale du timer
    this->readSensor();
}
