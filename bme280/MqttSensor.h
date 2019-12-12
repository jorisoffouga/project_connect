
#ifndef COMM_MQTT_H
#define COMM_MQTT_H
#include <QList>
#include "mqtthandler.h"

/*! \file MqttSensor.h
 * @author Eric Rebillon (eric.rebillon@ynov.com)
 * \brief A Document file.
*/


/**
 * @brief The MqttSensor class
 * @brief class allow connection of class
 */
class MqttSensor:public MqttHandler
{
public:
    MqttSensor(QString address, quint16 port, QList<QString> topicList);
    ~MqttSensor();
public slots:
    void onMessage(QMqttMessage message) override;
    void dataPublish(QString Topic , QJsonObject data);

private:
    QList<QString> *m_topiclist;
};

#endif // COMM_MQTT_H
