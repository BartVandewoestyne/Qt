#include "FooThread.h"
#include "BarThread.h"

#include <QCoreApplication>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    FooThread fooThread1(1);
    BarThread barThread1(11);
    BarThread barThread2(22);
  
    fooThread1.start();  // sets x to 1
    barThread1.start();  // sets x to 11
    barThread2.start();  // sets x to 22

    fooThread1.wait();
    barThread1.wait();
    barThread2.wait();

    fooThread1.print();
    barThread1.print();
    barThread2.print();

    return 0;
}
