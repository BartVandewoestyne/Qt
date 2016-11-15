/*!
 * WARNING: THIS IS NOT THE WAY TO DO IT!!!  SEE [1].
 *
 * References:
 *
 *   [1] http://blog.qt.io/blog/2010/06/17/youre-doing-it-wrong/
 */

#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <QThread>

class MyThread : public QThread
{
public:
    MyThread()
    {
        moveToThread(this);
    }
 
    void run();
 
signals:
    void progress(int);
    void dataReady(QByteArray);
 
public slots:
    void doWork();
    void timeoutHandler();
};

#endif  // MY_THREAD_H
