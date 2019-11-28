#include "airquality.h"

AirQuality::AirQuality()
{
    // Initialisation des json et variables du publish MQTT
    m_payload["data_tvoc"] = "";
    m_payload["data_co2"] = "";
    m_payload["id"] = "42";
    m_topic = "/sensor/air_quality";

    //Initialisation du timer et paramétrage de l'intervale
    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &AirQuality::timerSlot);
    m_timer->start(5000);
}


void AirQuality::readSensor()
{
    // Ouverture et test de l'existance des fichiers contenant les mesures athmosphérique
    QFile file_tvoc("/sys/bus/iio/devices/iio\:device0/in_concentration_voc_raw");
    if (!file_tvoc.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Erreur d'ouverture tvoc. tentative avec un autre fichier";
    }

    QFile file_co2("/sys/bus/iio/devices/iio\:device0/in_concentration_co2_raw");
    if (!file_co2.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Erreur d'ouverture co2. tentative avec un autre fichier";
    }

    /* lecture des fichiers sur la qualité de l'air et le taux de Co2
     * Seule la prmeière partie est conservée */
    QString data_tvoc = file_tvoc.readLine().split('\n')[0];
    QString data_co2 = file_co2.readLine().split('\n')[0];

    // fermeture des fichiers après la lecture
    file_tvoc.close();
    file_co2.close();

    qDebug() << "TVOC : " << data_tvoc << "\t CO2 : " << data_co2 << ".";

    // Ajout des données relevées au payload JSON
    m_payload["data_tvoc"] = data_tvoc;
    m_payload["data_co2"] = data_co2;

    // Emission du signal vers la fonction d'envoi MQTT
    emit(onDataSensor(m_topic, m_payload));
}

void AirQuality::timerSlot()
{
    // Appel de la fonction readSensor à chaque intervale du timer
    this->readSensor();
}

// Fichier de lecture de CO2 : /sys/bus/iio/devices/iio\:device0/in_concentration_co2_raw
