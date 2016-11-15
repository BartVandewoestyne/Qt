/*
 * References:
 *   [1] http://doc.qt.io/qt-4.8/qthread.html#details
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "worker.h"
#include <QObject>
#include <QThread>

class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;

public:

    Controller() {

        Worker *worker = new Worker;
        worker->moveToThread(&workerThread);

        connect(&workerThread, SIGNAL(finished()), worker, SLOT(deleteLater()));
        connect(this, SIGNAL(operate(QString)), worker, SLOT(doWork(QString)));
        connect(worker, SIGNAL(resultReady(QString)), this, SLOT(handleResults(QString)));

        workerThread.start();
    }

    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }

public slots:

    void handleResults(const QString &);

signals:

    void operate(const QString &);
};

#endif  // CONTROLLER_H
