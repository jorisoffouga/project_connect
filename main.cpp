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
