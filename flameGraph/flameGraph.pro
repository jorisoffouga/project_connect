TEMPLATE = app
TARGET = flameGraph
SOURCES += Sensor.cpp main.cpp SensorGpioData.cpp
HEADERS += Sensor.h SensorGpioData.h

INCLUDEPATH += ../mqtthandler
LIBS += -L../mqtthandler -lmqtthandler
QMAKE_LIBS += -lgpiodcxx
