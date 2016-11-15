/*!
 * References:
 *
 *   [1] http://blog.debao.me/2013/08/how-to-use-qthread-in-the-right-way-part-2/
 */

#include "Button.h"
#include "Test.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "From main thread: " << QThread::currentThread();

    Test test;
    Button btn(&test);
    btn.show();

    return a.exec();
}
