! include(../common.pri) {
    error("Couldn't find the common.pri file!")
}
TEMPLATE = app
TARGET = flameGraph
SOURCES += Sensor.cpp main.cpp SensorGpioData.cpp
HEADERS += Sensor.h SensorGpioData.h

QMAKE_LIBS += -lgpiodcxx
