#include "Worker.h"

#include <QDebug>
#include <QThread>
#include <QTimer>

class Thread : public QThread
{
    Q_OBJECT

private:
    void run()
    {
        qDebug() << "From work thread: " << currentThreadId();

        QTimer timer;
        Worker worker;

        connect(&timer, SIGNAL(timeout()), &worker, SLOT(onTimeout()));

        timer.start(1000);

        exec();
    }
};
