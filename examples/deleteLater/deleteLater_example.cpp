/*
 * Forum explanation 1:
 *
 *  "deleteLater() posts an event to the event queue (like a repaint event, a
 *   timer event or a network event). If the event is processed it deletes the
 *   object."
 *
 * Forum explanation 2:
 *
 *  "delete removes an object right at the time you call it. deleteLater calls
 *  delete on an object after all the events currently pending in the event
 *  loop are handled.
 *
 *  Imagine some object A reacting to some event in Qt (let's say a mouse click). A
 *  calls B::someMethod() which contains 'delete A;'. This code will crash: After
 *  B::someMethod() returns, code in object A will be executed.
 *
 *  'deleteLater(A);' on the other hand is save: A is still around after
 *  B::someMethod() returns. Only after the execution of the original mouse click
 *  is done and the Qt eventloop is executing again (== there is nothing to do) Qt
 *  will delete A."
 *
 * References:
 *
 *   [qtdocs] Qt 4.8 and Qt 5 documentation for QObject::deleteLater
 *     http://doc.qt.io/qt-4.8/qobject.html#deleteLater
 *     https://doc.qt.io/qt-5/qobject.html#deleteLater
 *
 *   [qt_wiki] Threads Events QObjects
 *     https://wiki.qt.io/Threads_Events_QObjects
 *
 *   [stackoverflow20140313] When to use deleteLater?
 *     https://stackoverflow.com/questions/22376298/when-to-use-deletelater
 *
 *   [stackoverflow20140208] How deleteLater() actually works in qt?
 *     http://stackoverflow.com/questions/21648598/how-deletelater-actually-works-in-qt
 *
 *   [tharez20120207] deleteLater()?
 *     https://forum.qt.io/topic/13838/solved-deletelater
 *
 *   [shaw20120202] To delete or not to delete
 *     http://blog.qt.io/blog/2012/02/02/qt-commercial-support-weekly-12-to-delete-or-not-to-delete-2/
 *
 *   [stackoverflow20110203] How delete and deleteLater works with regards to signals and slots in Qt?
 *     https://stackoverflow.com/questions/4888189/how-delete-and-deletelater-works-with-regards-to-signals-and-slots-in-qt
 *
 *   [gateau20100929] Fun with event loops and QObject::deleteLater()
 *     http://agateau.com/2010/fun-with-event-loops-and-qobjectdeletelater/
 *
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
