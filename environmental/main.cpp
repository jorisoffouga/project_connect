/**
 * @file main.cpp
 * @author Eric Rebillon (eric.rebillon@ynov.com)
 * @brief
 * @version 0.1
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <QCoreApplication>
#include <QObject>
#include "Sensor.h"


/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 * call the class contains the both class
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sensor *sensor = new Sensor();
    Q_UNUSED(sensor)

    a.exec();
}
