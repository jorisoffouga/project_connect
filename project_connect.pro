TEMPLATE = subdirs
SUBDIRS = mqtthandler gateway airquality flameGraph bme280

gateway.depends = mqtthandler
airquality.depends = mqtthandler
flameGraph.depends = mqtthandler
bme280.depends = mqtthandler

