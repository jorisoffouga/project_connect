#include "mqttcom.h"

// Constructeur : l'héritage de la class Mqtthandler permet de créer l'objet sans nécessiter d'ajout.
MqttCom::MqttCom(QString address, quint16 port, QList<QString> topicList):
    MqttHandler(address, port, topicList)
{}


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
