/*!
 * References:
 *
 *   [1] http://blog.debao.me/2013/08/how-to-use-qthread-in-the-right-way-part-1/
 */

#include "Worker.h"

#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"From main thread: "<<QThread::currentThreadId();

    QThread t;
    QTimer timer;
    Worker worker;

    QObject::connect(&timer, SIGNAL(timeout()), &worker, SLOT(onTimeout()));
    timer.start(1000);

    timer.moveToThread(&t); // Note that this line is not really necessary, as shown in Usage 2-1.
    worker.moveToThread(&t);

    t.start();

    return a.exec();
}
