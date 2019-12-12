TEMPLATE = subdirs
SUBDIRS = mqtthandler gateway airquality flameGraph bme280

gateway.depends = mqtthandler
airquality.depends = mqtthandler
flameGraph.depends = mqtthandler
bme280.depends = mqtthandler

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
