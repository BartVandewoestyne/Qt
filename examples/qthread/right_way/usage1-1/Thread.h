#ifndef THREAD_H
#define THREAD_H

#include <QDebug>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>

class Thread : public QThread
{
    Q_OBJECT

public:

    Thread() : m_stop(false)
    {}

public slots:

    void stop()
    {
        qDebug() << "Thread::stop() called from thread " << currentThreadId() << ".";
        QMutexLocker locker(&m_mutex);
        m_stop = true;
    }

private:

    QMutex m_mutex;
    bool m_stop;

    void run()
    {
        qDebug() << "Thread::run() called from thread " << currentThreadId() << ".";
        while (1) {
            {
                QMutexLocker locker(&m_mutex);
                if (m_stop) break;
            }
            msleep(10);
        }
    }
};

#endif  // THREAD_H
