#include <QCoreApplication>
#include "mqttcom.h"
#include "airquality.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AirQuality *sensor = new AirQuality();
    Q_UNUSED(sensor);

    return a.exec();
}
