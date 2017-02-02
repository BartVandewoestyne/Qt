/*
 * References:
 *   [1] http://doc.qt.io/qt-4.8/qobject.html#deleteLater
 *   [2] http://blog.qt.io/blog/2012/02/02/qt-commercial-support-weekly-12-to-delete-or-not-to-delete-2/
 *   [3] http://agateau.com/2010/fun-with-event-loops-and-qobjectdeletelater/
 *   [4] https://forum.qt.io/topic/13838/solved-deletelater
 *   [5] http://stackoverflow.com/questions/21648598/how-deletelater-actually-works-in-qt
 */

#include "Car.h"

#include <QApplication>
#include <QDebug>
#include <QTimer>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QEventLoop loop;
    QTimer timer;
    
    Car* pCar = new Car();

    timer.setSingleShot(true);
    QObject::connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));

    timer.start(5000);

    // Situation 1: event loop is not running (deleteLater() is called on an
    // object before exec()), then object is deleted once the event loop is
    // started.
    //delete pCar;  // both car and wheel deleted.
    //loop.exec();

    // Situation 2: deleteLater() is called after the main event loop
    // has stopped -> object will not be deleted.
    //loop.exec();
    //delete pCar;  // only car deleted

    // Situation 3: if deleteLater() is called on an object that lives in a
    // thread with no running event loop, the object will be destroyed when
    // the thread finishes.
    delete pCar;  // only car deleted??? (maybe because this is not a separate thread, but the main thread?)
}
