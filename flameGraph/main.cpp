/*!
* \file main.cpp
* \brief Code flame sensor & led 7 segments
* \author Thomas Abgrall
* \date 22.11.2019
* \version 1.0
*/

#include <QCoreApplication>
#include "Sensor.h"

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sensor *sensor = new Sensor(ADRESS, PORT, {TOPICSUBSCRIB});
    Q_UNUSED(sensor);

    return a.exec();
}
