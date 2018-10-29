#ifndef BASE_THREAD_H
#define BASE_THREAD_H

#include <QThread>
#include <QDebug>

class BaseThread : public QThread
{
    Q_OBJECT
public:
    BaseThread(int newValue) : x(0), mvNewValue(newValue) {}
    void run();
protected:
    int x;
    int mvNewValue;
};

#endif  // BASE_THREAD_H
