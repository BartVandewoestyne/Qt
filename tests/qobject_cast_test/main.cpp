/*
 * According to [2], the qobject_cast() function behaves similarly to the
 * standard C++ dynamic_cast(), but it has these extra two advantages:
 *
 *   Advantage 1: it doesn't require RTTI support
 *   Advantage 2: it works across dynamic library boundaries
 *
 * Furthermore, according to [3], there is another advantage:
 *
 *   Advantage 3: you may find that qobject_cast works 5 to 10 times
 *                faster than dynamic_cast, depending on what compiler you use. 
 *
 * TODO:
 *   - Can we use only one do_cast_stuff(QObject*) function and pass
 *     qobject_cast and dynamic_cast as function parameters to this function?
 *
 *   - Can we avoid the extra qDebug() statements that are used to force the
 *     compiler not to optimize away code?
 *
 * References:
 *
 *   [1] http://doc.qt.io/qt-4.8/metaobjects.html
 *   [2] http://doc.qt.io/qt-4.8/qobject.html#qobject_cast
 *   [3] http://www.ics.com/designpatterns/book/qtrtti.html
 */

#include "mywidget.h"

#include <QApplication>
#include <QDebug>
#include <QElapsedTimer>
#include <QLabel>
#include <QObject>
#include <QWidget>

const int NB_ITERATIONS = 1000000;

qint64 do_qobject_cast_stuff(QObject* obj)
{
    QWidget* widget;
    MyWidget* myWidget;
    QLabel* label;

    QElapsedTimer timer;
    timer.start();
    for (int i = 0; i < NB_ITERATIONS; ++i)
    {
        widget = qobject_cast<QWidget*>(obj);
        myWidget = qobject_cast<MyWidget*>(obj);
        label = qobject_cast<QLabel*>(obj);
    }
    qint64 theTimeInMs = timer.elapsed();
    qDebug() << "qobject_cast code took " << theTimeInMs << " milliseconds.";

    // To avoid warnings about unused variables and to make sure the
    // compiler doesn't remove code while optimizing.
    qDebug() << widget; 
    qDebug() << myWidget;
    qDebug() << label;

    return theTimeInMs;
}

qint64 do_dynamic_cast_stuff(QObject* obj)
{
    QWidget* widget;
    MyWidget* myWidget;
    QLabel* label;

    QElapsedTimer timer;
    timer.start();
    for (int i = 0; i < NB_ITERATIONS; ++i)
    {
        widget = dynamic_cast<QWidget*>(obj);
        myWidget = dynamic_cast<MyWidget*>(obj);
        label = dynamic_cast<QLabel*>(obj);
    }
    qint64 theTimeInMs = timer.elapsed();
    qDebug() << "dynamic_cast code took " << theTimeInMs << " milliseconds.";

    // To avoid warnings about unused variables and to make sure the
    // compiler doesn't remove code while optimizing.
    qDebug() << widget; 
    qDebug() << myWidget;
    qDebug() << label;

    return theTimeInMs;
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QObject* obj = new MyWidget;

    qint64 object_cast_time = do_qobject_cast_stuff(obj);
    qint64 dynamic_cast_time = do_dynamic_cast_stuff(obj);

    qDebug() << "dynamic_cast was " << static_cast<float>(dynamic_cast_time)/object_cast_time << " times slower.";

    return 0;
}
