/*!
 * References:
 *
 *   http://doc.qt.io/qt-4.8/threads-starting.html
 */

#include "mythread.h"
#include <QCoreApplication>
#include <QThread>
#include <iostream>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    MyThread myThread;
    myThread.start();

    return app.exec();
}
