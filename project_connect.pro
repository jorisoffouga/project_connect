TEMPLATE = subdirs
SUBDIRS = mqtthandler gateway airquality flameGraph bme280

gateway.depends = mqtthandler
airquality.depends = mqtthandler
flameGraph.depends = mqtthandler
bme280.depends = mqtthandler

# custom target 'doc' in *.pro file
dox.target = doc
dox.commands = doxygen ../Doxyfile; \
    test -d doxydoc/html/images || mkdir doxydoc/html/images; \
    cp documentation/images/* doxydoc/html/images
dox.depends =

# somewhere else in the *.pro file
QMAKE_EXTRA_TARGETS += dox
