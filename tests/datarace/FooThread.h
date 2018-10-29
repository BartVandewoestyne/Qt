#ifndef FOO_THREAD_H
#define FOO_THREAD_H

#include "BaseThread.h"

class FooThread : public BaseThread
{
public:
    FooThread(int newValue) : BaseThread(newValue) {}
    void print();
};

#endif  // FOO_THREAD_H
