/*!
* \file main.cpp
* \brief Code flame sensor & led 7 segments
* \author Thomas Abgrall
* \date 22.11.2019
* \version 1.0
*/

#include <QCoreApplication>
#include "mqtthandler.h"
#include "read_file.h"
#include "comm_mqtt.h"
#include "interobj.h"

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
    InterObj *inter = new InterObj();

    return a.exec();
}
