#include "airquality.h"
#include "QThread"

AirQuality::AirQuality()
{
    m_timer = new QTimer();
    m_mqtt = new MqttCom(MQTT_ADDR, MQTT_PORT, {});

    connect(m_timer, &QTimer::timeout, this, &AirQuality::readSensor);
    connect(this, &AirQuality::onDataSensor, m_mqtt, &MqttCom::onMeasureSensor);

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
    QString co2;
    QString tvoc;
    QJsonObject jobject;

    co2 = readCo2();
    QThread::msleep(300);
    tvoc = readTvoc();

    // Ajout des données relevées au payload JSON
    if(co2 != "Error" && tvoc != "Error"){
        jobject["data_co2"] = co2;
        jobject["data_tvoc"] = tvoc;
        emit onDataSensor(AIRQUALITYTOPIC, jobject);
    }
}

void AirQuality::timerSlot()
{
    // Appel de la fonction readSensor à chaque intervale du timer
    this->readSensor();
}
