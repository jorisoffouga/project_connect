#include "interobj.h"
#include "comm_mqtt.h"
#include "read_file.h"

InterObj::InterObj(QObject *parent) : QObject(parent)
{
    QList<QString>topicList {"/feu"};
    m_read_file = new MyTimer();
    m_comm = new Comm_Mqtt("localhost", 1883, topicList);

    QObject::connect(m_read_file,SIGNAL(DataToSend(QString, QJsonObject)),m_MqttHandler,SLOT(publishData(QString *, QJsonObject *)));

    m_read_file->timer->start(100);
}

InterObj::~InterObj()
{

}
