#ifndef READ_FILE_H
#define READ_FILE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QEvent>
#include <QTimer>
#include <QObject>
#include "comm_mqtt.h"


class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(QWidget *parent=0);
    QFile file ;
    QTextStream flux;
    QTimer* timer;
    QString data_read;
    QString old_data;

public slots:
    void timerEvent();

private:

signals:
    void DataToSend(QString *, QJsonObject *);
};

#endif // READ_FILE_H
