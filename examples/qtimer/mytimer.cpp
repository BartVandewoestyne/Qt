#include "mytimer.h"
#include <QDebug>

MyTimer::MyTimer()
{
    // create a timer
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
            this, SLOT(myTimerSlot()));

    // msec
    timer->start(1000);

    QTimer::singleShot(3000, this, SLOT(mySingleShotSlot()));
}

void MyTimer::myTimerSlot()
{
    qDebug() << "MyTimer::myTimerSlot()";
}

void MyTimer::mySingleShotSlot()
{
    qDebug() << "MyTimer::mySingleShotSlot()";
}
