! include(../common.pri) {
    error("Couldn't find the common.pri file!")
}

TEMPLATE = lib
SOURCES = mqtthandler.cpp
HEADERS = mqtthandler.h
