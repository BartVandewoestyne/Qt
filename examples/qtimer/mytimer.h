#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>

class MyTimer : public QObject
{
    Q_OBJECT

public:

    MyTimer();

    QTimer* timer;

public slots:

    void myTimerSlot();
    void mySingleShotSlot();
};

#endif  // MYTIMER_H
