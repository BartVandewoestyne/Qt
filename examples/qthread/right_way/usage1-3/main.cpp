/*!
 * References:
 *
 *   [1] http://blog.debao.me/2013/08/how-to-use-qthread-in-the-right-way-part-1/
 */

#include "Thread.h"

#include <QCoreApplication>
#include <QDebug>
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "From main thread: " << QThread::currentThreadId();

    Thread t;
    t.start();

    return a.exec();
}
