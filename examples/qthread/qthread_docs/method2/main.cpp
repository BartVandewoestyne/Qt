/*!
 * References:
 *
 *   http://doc.qt.io/qt-4.8/qthread.html#details
 */

#include "MyObject.h"
#include <QCoreApplication>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    MyObject myObject;
    myObject.startWorkInAThread();

    return app.exec();
}
