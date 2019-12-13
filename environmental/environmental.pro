! include(../common.pri) {
    error("Couldn't find the common.pri file!")
}
TEMPLATE = app
TARGET = environmental
SOURCES += MqttSensor.cpp main.cpp Sensor.cpp SensorValue.cpp
HEADERS += MqttSensor.h Sensor.h SensorValue.h

