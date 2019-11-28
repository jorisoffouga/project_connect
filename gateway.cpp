#include "gateway.h"


Gateway::Gateway(QString address, quint16 port, QList<QString> topicList):
    MqttHandler(address,port, topicList)
{
}

Gateway::~Gateway()
{

}

void Gateway::onMessage(QMqttMessage message) {
    qDebug() << "mqtt message receive from topic : " <<  message.topic().name();
    qDebug() << "payload : " << message.payload();

    QStringList topic_parsed = message.topic().name().split('/');
    QString topic_origin = topic_parsed[1];
    QString topic_destination = topic_parsed[2];

    QString new_topic = "Error";

    QJsonDocument dataJSON = QJsonDocument::fromJson(message.payload());
    QJsonObject payload = dataJSON.object();

    if(topic_origin == "sensor"){
        new_topic = "/server/" + topic_destination;
    }else if(topic_origin == "gateway"){
        new_topic = "/command/" + topic_destination;
    }else{
        qDebug() << "ERROR : unknown topic" << message.topic().name() <<".";
    }
    qDebug() << "Send data to server " << new_topic <<".";
    this->publishData(new_topic, payload);
}
