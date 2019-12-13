TEMPLATE = subdirs
SUBDIRS = mqtthandler gateway airquality flameGraph environmental

gateway.depends = mqtthandler
airquality.depends = mqtthandler
flameGraph.depends = mqtthandler
environmental.depends = mqtthandler

# custom target 'doc' in *.pro file
dox.target = doc
dox.commands = doxygen ../Doxyfile;
dox.depends =

# somewhere else in the *.pro file
QMAKE_EXTRA_TARGETS += dox
