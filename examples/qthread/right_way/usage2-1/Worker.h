#ifndef WORKER_H
#define WORKER_H

#include <QDebug>
#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT

private slots:

    void onTimeout()
    {
        qDebug() << "Worker::onTimeout() got called from " << QThread::currentThreadId();
    }

};

#endif  // WORKER_H
