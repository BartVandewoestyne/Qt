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
        // When running the code, you should notice that this slot doens't run in the main thread, which is good.
        qDebug() << "Worker::onTimeout() got called from " << QThread::currentThreadId();
    }

};

#endif  // WORKER_H
