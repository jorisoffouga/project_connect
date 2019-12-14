#ifndef AIRQUALITY_MQTT_H
#define AIRQUALITY_MQTT_H

#include "MqttHandler.h"

class AirQualityMqtt : public MqttHandler
{
    Q_OBJECT
public:
    AirQualityMqtt(QString address, quint16 port, QList<QString> topicList);
    ~AirQualityMqtt();

public slots:
    void onMeasureSensor(QString topic, QJsonObject jsonData);


};
#endif // AIRQUALITY_MQTT_H
