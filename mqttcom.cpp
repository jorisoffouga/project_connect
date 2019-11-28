#include "mqttcom.h"


MqttCom::MqttCom(QString address, quint16 port, QList<QString> topicList): MqttHandler(address, port, topicList){}


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

void MqttCom::onMeasureSensor(QString topic, QJsonObject jsonData)
{
    qDebug() << jsonData;
    QMqttTopicFilter topicFilter;
    topicFilter.setFilter(topic);
    QJsonDocument data( jsonData );
    m_client->publish(topic, data.toJson());
}
