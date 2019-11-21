#include "mqttherit.h"


MqttHerit::MqttHerit(QString address, quint16 port, QList<QString> topicList): MqttHandler(address, port, topicList){}


void MqttHerit::onMessage(QMqttMessage message) {
    quint32 rc;
    QString topic = "/data";
    QJsonObject jobject;

   qDebug() << "mqtt message receive fils from topic : " <<  message.topic().name() << " payload : " << message.payload();

   if(message.topic().name() == "/test"){
       jobject["Temperature"] = QString::number(25);
       jobject["Type"] = "Data";
       this->publishData(topic, jobject);
   }else if(message.topic().name() == "/stuff"){
       QJsonDocument dataJSON = QJsonDocument::fromJson(message.payload());
       QJsonObject data = dataJSON.object();
       int value1 = data["value1"].toInt();
       int value2 = data["value2"].toInt();

       qDebug() << value1;
       qDebug() << value2;
   }
}
