#include "WorkerThread.h"

void MyObject::startWorkInAThread()
{
    WorkerThread *workerThread = new WorkerThread;
    connect(workerThread, SIGNAL(finished()),
            workerThread, SLOT(deleteLater()));
    workerThread->start();
}
