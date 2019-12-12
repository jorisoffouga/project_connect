#include "airquality.h"
#include "QThread"

AirQuality::AirQuality()
{
    // Initialisation des json et variables du publish MQTT
    m_payload["data_tvoc"] = "";
    m_payload["data_co2"] = "";
    m_payload["id"] = "42";
    m_topic = "/sensor/air_quality";

    //Initialisation du t/sys/bus/iio/devices/iio\:device1/in_concentration_co2_rawimer/sys/bus/iio/devices/iio\:device1/in_concentration_co2_raw et paramétrage de l'intervale
    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &AirQuality::readSensor);
    m_timer->start(5000);
}

QString AirQuality::readCo2()
{
    QString read;
    QFile file(co2Path_dev1);
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
        file.setFileName(co2Path_dev0);

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
    qDebug() << "Co2";
    qDebug() << data;
    qDebug() << read;
    return read;
}

QString AirQuality::readTvoc()
{
    QString read;
    QFile file(tvocPath_dev1);
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
        file.setFileName(tvocPath_dev0);
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
    qDebug() << "TVOC:";
    qDebug() << read;
    qDebug() << data;
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
    /*// Ouverture et test de l'existance des fichiers contenant les mesures athmosphérique
    QFile file_tvoc("/sys/bus/iio/devices/iio\:device1/in_concentration_voc_raw");
    if (!file_tvoc.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Erreur d'ouverture tvoc. tentative avec un autre fichier";
    }

    QFile file_co2("/sys/bus/iio/devices/iio\:device1/in_concentration_co2_raw");
    if (!file_co2.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Erreur d'ouverture co2. tentative avec un autre fichier";
    }*/

    /* lecture des fichiers sur la qualité de l'air et le taux de Co2
     * Seule la prmeière partie est conservée */
    /*QString data_tvoc = file_tvoc.readLine().split('\n')[0];
    QString data_co2 = file_co2.readLine().split('\n')[0];

    // fermeture des fichiers après la lecture
    file_tvoc.close();1000
    file_co2.close();

    qDebug() << "TVOC : " << data_tvoc << "\t CO2 : " << data_co2 << ".";


    m_payload["data_tvoc"] = data_tvoc;
    m_payload["data_co2"] = data_co2;

    // Emission du signal vers la fonction d'envoi MQTT
    emit(onDataSensor(m_topic, m_payload));*/
}

void AirQuality::timerSlot()
{
    // Appel de la fonction readSensor à chaque intervale du timer
    this->readSensor();
}

// Fichier de lecture de CO2 : /sys/bus/iio/devices/iio\:device0/in_concentration_co2_raw
