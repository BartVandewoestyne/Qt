#ifndef WORKER_THREAD_H
#define WORKER_THREAD_H

#include <QString>
#include <QThread>
#include <iostream>

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    WorkerThread(QObject* parent)
      : QThread(parent) {}

    void run() {
        QString result;
        /* expensive or blocking operation  */
        std::cout << "WorkerThread::run()" << std::endl;
        emit resultReady(result);
    }

signals:
    void resultReady(const QString &s);
};

#endif  // WORKER_THREAD_H
