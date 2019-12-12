#include "mqttcom.h"

// Constructeur : l'héritage de la class Mqtthandler permet de créer l'objet sans nécessiter d'ajout.
MqttCom::MqttCom(QString address, quint16 port, QList<QString> topicList): MqttHandler(address, port, topicList){}

// Fonction qui se déclenche lors de la réception d'un message sur l'un des topic suivi
// Code inutile, à réécrire ou à supprimer lorsque le groupe sera d'accord sur l'usage du topic /command/sensor
void MqttCom::onMessage(QMqttMessage message) {
    QJsonObject jobject;
    QString topic = "data";

    qDebug() << "mqtt message receive fils from topic : " <<  message.topic().name() << " payload : " << message.payload();

    if(message.topic().name() == "/sensor/tvoc"){
        jobject["data"] = "test_tvoc";
    }else if(message.topic().name() == "/sensor/co2"){
        jobject["data"] = "test_co2";
    }else{
        qDebug() << "Aucun cas prévu";
    }

    jobject["status"] = "Connected";
    jobject["id"] = "42";

    this->publishData(topic, jobject);
}

/* Fonction de formattage du contenu envoyé vers la fonction d'emission.
 * Appellée par le signal onDataSensor */
void MqttCom::onMeasureSensor(QString topic, QJsonObject jsonData)
{
    qDebug() << jsonData;
    QMqttTopicFilter topicFilter;
    topicFilter.setFilter(topic);
    QJsonDocument data( jsonData );
    m_client->publish(topic, data.toJson());
}
