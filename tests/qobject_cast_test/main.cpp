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
 *   Modify this code so that the above three advantages of qobject_cast are
 *   illustrated.
 *
 * References:
 *
 *   [1] http://doc.qt.io/qt-4.8/metaobjects.html
 *   [2] http://doc.qt.io/qt-4.8/qobject.html#qobject_cast
 *   [3] http://www.ics.com/designpatterns/book/qtrtti.html
 */

#include "mywidget.h"

#include <QApplication>
#include <QLabel>
#include <QObject>
#include <QWidget>

void do_qobject_cast_stuff(QObject* obj)
{
    QWidget* widget = qobject_cast<QWidget*>(obj);
    MyWidget* myWidget = qobject_cast<MyWidget*>(obj);
    QLabel* label = qobject_cast<QLabel*>(obj);
}

void do_dynamic_cast_stuff(QObject* obj)
{
    QWidget* widget = dynamic_cast<QWidget*>(obj);
    MyWidget* myWidget = dynamic_cast<MyWidget*>(obj);
    QLabel* label = dynamic_cast<QLabel*>(obj);
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QObject* obj = new MyWidget;

    do_qobject_cast_stuff(obj);
    do_dynamic_cast_stuff(obj);

    return 0;
}
