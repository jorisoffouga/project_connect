TEMPLATE = subdirs
SUBDIRS = mqtthandler gateway airquality flameGraph

gateway.depends = mqtthandler
airquality.depends = mqtthandler
flameGraph.depends = mqtthandler

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

