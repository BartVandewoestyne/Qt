#include "Worker.h"

#include <QDebug>

// --- CONSTRUCTOR ---
Worker::Worker() {
    // you could copy data from constructor arguments to internal variables here.

    // Important note: NEVER allocate heap objects (using new) in the constructor
    // of this QObject class, as this allocation is then performed on the main
    // thread and not on the new QThread instance, meaning that the newly created
    // object is then owned by the main thread and not the QThread instance.  This
    // will make your code fail to work.  Instead, allocate such resources in the
    // main function slot such as process() in this case as when that is called,
    // the object will be on the new thread instance and thus it will own the resource.
}
 
// --- DECONSTRUCTOR ---
Worker::~Worker() {
    // free resources
}
 
// --- PROCESS ---
// Start processing data.
void Worker::process() {
    int i = 0;
    while (true)
    {
        qDebug() << "hello from thread";
    }
    // allocate resources using new here
    qDebug("Hello World!");
    emit finished();
}
