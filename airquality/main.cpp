#include <QCoreApplication>
#include "AirQualityMqtt.h"
#include "AirQuality.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AirQuality *sensor = new AirQuality();
    Q_UNUSED(sensor);

    return a.exec();
}
