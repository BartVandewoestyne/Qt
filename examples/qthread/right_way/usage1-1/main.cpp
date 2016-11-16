/*!
 * References:
 *
 *   [1] http://blog.debao.me/2013/08/how-to-use-qthread-in-the-right-way-part-1/
 */

#include "Thread.h"

#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "From main thread: " << QThread::currentThreadId();

    QPushButton btn("Stop Thread");
    Thread t;

    QObject::connect(&btn, SIGNAL(clicked()), &t, SLOT(stop()));
    QObject::connect(&t, SIGNAL(finished()), &a, SLOT(quit()));

    t.start();
    btn.show();

    return a.exec();
}
