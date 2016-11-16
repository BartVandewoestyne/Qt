#include "MyApplication.h"

#include "Worker.h"

#include <QDebug>
#include <QString>
#include <QThread>

void MyApplication::doIt()
{
    QThread* thread = new QThread;
    Worker* worker = new Worker();
    worker->moveToThread(thread);

    connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}

void MyApplication::errorString(QString error)
{
    qDebug() << error;
}