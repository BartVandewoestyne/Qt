#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT
    QThread workerThread;

public slots:
    void doWork(const QString &parameter) {
        std::cout << "Worker::doWork(const QString&)" << std::endl;
        emit resultReady(result);
    }

signals:
    void resultReady(const QString &result);
};

#endif  // WORKER_H
