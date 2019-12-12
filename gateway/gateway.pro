! include(../common.pri) {
    error("Couldn't find the common.pri file!")
}

TEMPLATE = app
TARGET = gateway
SOURCES += gateway.cpp main.cpp
HEADERS += gateway.h
