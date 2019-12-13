! include(../common.pri) {
    error("Couldn't find the common.pri file!")
}
TEMPLATE = lib
TARGET = mqtthandler
CONFIG += staticlib
SOURCES = mqtthandler.cpp
HEADERS = mqtthandler.h \
    mqttconfig.h
