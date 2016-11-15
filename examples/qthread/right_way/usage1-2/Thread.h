/*!
 * WRONG USAGE!!!
 */

#include <QtCore>

class Thread : public QThread
{
    Q_OBJECT

private slots:

    void onTimeout()
    {
        qDebug() << "Thread::onTimeout got called from thread " << QThread::currentThreadId();
    }

private:

    void run()
    {
        qDebug() << "Inside Thread::run() with thread ID " << currentThreadId();

        QTimer timer;
        connect(&timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

        timer.start(1000);

        exec();
    }

};
