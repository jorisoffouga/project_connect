#include "mqttherit.h"


MqttHerit::MqttHerit(QString address, quint16 port, QList<QString> topicList): MqttHandler(address, port, topicList){}


void MqttHerit::onMessage(QMqttMessage message) {
//    quint32 rc;
    QJsonObject jobject;
    QString topic = "data";

   qDebug() << "mqtt message receive fils from topic : " <<  message.topic().name() << " payload : " << message.payload();

   if(message.topic().name() == "/test"){
       jobject["data"] = "test_data";
   }else if(message.topic().name() == "/sensor/tvoc"){
       jobject["data"] = "test_tvoc";
   }else if(message.topic().name() == "/sensor/co2"){
       jobject["data"] = "test_co2";
   }else if(message.topic().name() == "/stuff"){
       topic = message.topic().name();
       QJsonDocument dataJSON = QJsonDocument::fromJson(message.payload());
       QJsonObject data = dataJSON.object();
       int value1 = data["value1"].toInt();
       int value2 = data["value2"].toInt();

       qDebug() << value1;
       qDebug() << value2;
   }else{
       qDebug() << "Aucun cas prévu";
   }

   jobject["status"] = "Connected";
   jobject["id"] = "42";
   this->publishData(topic, jobject);
}
