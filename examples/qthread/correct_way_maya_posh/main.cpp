/*!
 * References:
 *
 *   [1] https://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/
 *
 *  TODO: this does not compile yet.  We should move the thread stuff to another class.
 */

#include "Worker.h"

#include <QCoreApplication>
#include <QString>
#include <QThread>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    QThread* thread = new QThread;
    Worker* worker = new Worker();
    worker->moveToThread(thread);

    connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();

    return app.exec();
}
