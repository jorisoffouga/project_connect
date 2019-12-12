! include(../common.pri) {
    error("Couldn't find the common.pri file!")
}
TEMPLATE = app
TARGET = flameGraph
SOURCES += Sensor.cpp main.cpp SensorGpioData.cpp
HEADERS += Sensor.h SensorGpioData.h

INCLUDEPATH += ../mqtthandler
LIBS += -L../mqtthandler -lmqtthandler
QMAKE_LIBS += -lgpiodcxx
