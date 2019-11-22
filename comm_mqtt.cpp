#include "comm_mqtt.h"
#include "mqtthandler.h"
#include <QString>


Comm_Mqtt::Comm_Mqtt(QString address, quint16 port, QList<QString> topicList):MqttHandler(address, port, topicList)
{
    address = "localhost";
    port = 1883;
    topicList.append("/feu");
    topicList.append("/test");
    QString old_value;
}

void Comm_Mqtt::treatment(QMqttMessage message)
{
    QString msgRecu = message.topic().name();

    int resu_comp = QString::compare(msgRecu,"/test");
    if (resu_comp == 0) {
        // recup num
        // affiche num
    }
    else {
        qDebug() << "a wrong topic was ask";
    }
}

void Comm_Mqtt::SendData(QString &topic, QJsonObject &msg)
{
        MqttHandler::publishData(topic,msg);
}

void Comm_Mqtt::onMessage(QMqttMessage message){
    qDebug() << "mqtt message receive fils from topic : " <<  message.topic().name() << " payload : " <<
                message.payload();
    treatment(message);
}



