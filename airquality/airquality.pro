! include(../common.pri) {
    error("Couldn't find the common.pri file!")
}
TEMPLATE = app
TARGET = airquality
SOURCES += airquality.cpp main.cpp mqttcom.cpp
HEADERS += airquality.h mqttcom.h

INCLUDEPATH += ../mqtthandler
LIBS += -L../mqtthandler -lmqtthandler
