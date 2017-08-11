/*
 * My own example about how to use QWaitCondition.
 *
 * Start by running this example, and observing how the output is not
 * always 'Hello' followed by 'Bart' (sometimes it is, but this is by accident).
 *
 * Then, comment in the QWaitCondition code, and see how we now consequently
 * have a 'Hello' followed by a 'Bart'.
 *
 * TODO: check for correctness!  Note for example that the documentation
 *       for QWaitCondition::wait(QMutex*, unsigned long) mentions that
 *       the mutex must be initially locked by the calling thread.  According
 *       to http://doc.qt.io/qt-4.8/qmutex.html#details the mutex is created
 *       in an unlocked state...
 */

#include <QCoreApplication>
#include <QDebug>
#include <QMutex>
#include <QObject>
#include <QThread>
#include <QWaitCondition>

#include <cstdio>
#include <cstdlib>

QWaitCondition bartWritten;
QWaitCondition helloWritten;
QMutex mutex;

class ThreadA : public QThread
{
    Q_OBJECT
public:
    ThreadA(QObject *parent = NULL) : QThread(parent)
    {}

    void run()
    {
        for (int i = 0; i < 10; ++i)
        {
            //if (i != 0)  // to avoid deadlock
            //{
            //    bartWritten.wait(&mutex);
            //}
            qDebug() << "Hello";
            //helloWritten.wakeAll();
        }
    }
};

class ThreadB : public QThread
{
    Q_OBJECT
public:
    ThreadB(QObject *parent = NULL) : QThread(parent)
    {}

    void run()
    {
        for (int i = 0; i < 10; ++i)
        {
            //helloWritten.wait(&mutex);
            qDebug() << "Bart";
            //bartWritten.wakeAll();
        }
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    ThreadA threadA;
    ThreadB threadB;

    threadA.start();
    threadB.start();

    threadA.wait();
    threadB.wait();

    return 0;
}

#include "waitconditions.moc"
