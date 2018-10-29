#ifndef BAR_THREAD_H 
#define BAR_THREAD_H

#include "BaseThread.h"

class BarThread : public BaseThread
{
public:
    BarThread(int newValue) : BaseThread(newValue) {}
    void print();
};

#endif  // BAR_THREAD_H
