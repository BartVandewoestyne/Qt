#include "MyObject.h"

#include "WorkerThread.h"
#include <QString>

void MyObject::startWorkInAThread()
{
    WorkerThread *workerThread = new WorkerThread(this);
    connect(workerThread, SIGNAL(resultReady(QString)), this, SLOT(handleResults(QString)));
    connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
    workerThread->start();
}
