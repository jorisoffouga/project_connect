#include <QCoreApplication>
#include "mqtthandler.h"
#include "read_file.h"
#include "comm_mqtt.h"
#include "interobj.h"


int main(int argc, char *argv[])
{
    qDebug() << "Avant le lancement du timer ";

    QCoreApplication a(argc, argv);
    qDebug() << "Avant le lancement du timer ";

    InterObj *inter = new InterObj();

    return a.exec();
}



/*
class MqttFils : MqttHandler
{
public:
    MqttFils(QString address, quint16 port, QList<QString> topicList): MqttHandler(address, port, topicList){
    }

public slots:
    void onMessage(QMqttMessage message) override{
        quint32 rc;
        QString topic = "/data";
        QJsonObject jobject;

        qDebug() << "mqtt message receive fils from topic : " <<  message.topic().name() << " payload : " <<
                    message.payload();

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
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString address = "localhost";
    quint16 port = 1883;
    QList<QString> topicList;
    topicList.append("/stuff");
    topicList.append("/test");

    MqttFils *mqtt = new MqttFils(address, port, topicList);

    return a.exec();
}
*/
