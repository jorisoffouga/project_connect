#ifndef ReceiveData_H
#define ReceiveData_H
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include "CommMqtt.h"


class ReceiveData : public QObject
{
    Q_OBJECT
public:
    ReceiveData(QWidget *parent=0);
    QFile file ;
    QTextStream flux;
    QTimer* timer;
    int m_data_read;
    int m_old_data;

public slots:
    void timerEvent();

private:

signals:
    void DataToSend(QString, QJsonObject);
};

#endif // ReceiveData_H
