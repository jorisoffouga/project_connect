! include(../common.pri) {
    error("Couldn't find the common.pri file!")
}
TEMPLATE = lib
TARGET = mqtthandler
CONFIG += staticlib
SOURCES = \
    MqttHandler.cpp
HEADERS = \
    MqttHandler.h \
    Mqttconfig.h
