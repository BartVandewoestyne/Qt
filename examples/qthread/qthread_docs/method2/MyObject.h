#ifndef MY_OBJECT_H
#define MY_OBJECT_H

#include <QObject>

class MyObject : public QObject
{
Q_OBJECT

public:
    ~MyObject() {};
    void startWorkInAThread();
};

#endif  // MY_OBJECT_H
