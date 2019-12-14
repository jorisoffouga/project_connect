! include(../common.pri) {
    error("Couldn't find the common.pri file!")
}

TEMPLATE = app
TARGET = gateway
SOURCES += main.cpp \
    GatewayMqtt.cpp
HEADERS += \
    GatewayMqtt.h
