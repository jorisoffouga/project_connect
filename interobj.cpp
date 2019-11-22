#include "interobj.h"
#include "comm_mqtt.h"
#include "read_file.h"


/**
 * @brief Construct a new Inter Obj:: Inter Obj object
 * 
 * @param parent 
 */
InterObj::InterObj(QObject *parent) : QObject(parent)
{
    QList<QString>topicList {TOPICSUBSCRIB};
    m_read_file = new MyTimer();
    m_comm = new Comm_Mqtt("localhost", 1883, topicList);

    connect(m_read_file, &MyTimer::DataToSend, m_comm, &Comm_Mqtt::SendData);
}

InterObj::~InterObj()
{

}
