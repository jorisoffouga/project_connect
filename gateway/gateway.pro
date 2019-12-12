TEMPLATE = app
TARGET = gateway
SOURCES += gateway.cpp main.cpp
HEADERS += gateway.h

INCLUDEPATH += ../mqtthandler
LIBS += -L../mqtthandler -lmqtthandler
