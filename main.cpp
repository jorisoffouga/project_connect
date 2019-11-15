#include <QCoreApplication>
#include "mqtthandler.h"

class MqttFils : MqttHandler
{
public:
    MqttFils(QString address, quint16 port, QList<QString> topicList): MqttHandler(address, port, topicList){
    }

public slots:
    void onMessage(QMqttMessage message) override{
        qDebug() << "mqtt message receive fils from topic : " <<  message.topic().name() << " payload : " <<
                    message.payload();
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
