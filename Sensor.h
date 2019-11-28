#ifndef SENSOR_H
#define SENSOR_H
#include "CommMqtt.h"
#include "ReceiveData.h"

#define TOPICSUBSCRIB "/command"


class Sensor : public QObject
{
    Q_OBJECT
public:
    Sensor(QObject *parent = 0);
    ~Sensor();

private:
    ReceiveData *m_read_file;
    CommMqtt *m_comm;
    MqttHandler *m_MqttHandler;
};

#endif // SENSOR_H
