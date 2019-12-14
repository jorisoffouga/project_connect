! include(../common.pri) {
    error("Couldn't find the common.pri file!")
}
TEMPLATE = app
TARGET = airquality
SOURCES += main.cpp \
    AirQuality.cpp \
    AirQualityMqtt.cpp
HEADERS += \
    AirQuality.h \
    AirQualityMqtt.h
