#ifndef INTEROBJ_H
#define INTEROBJ_H
#include "comm_mqtt.h"
#include "read_file.h"

#define TOPICSUBSCRIB "/command"


class InterObj : public QObject
{
    Q_OBJECT
public:
    InterObj(QObject *parent = 0);
    ~InterObj();

private:
    MyTimer *m_read_file;
    Comm_Mqtt *m_comm;
    MqttHandler *m_MqttHandler;
};

#endif // INTEROBJ_H
