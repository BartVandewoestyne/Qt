#include "Worker.h"

// --- CONSTRUCTOR ---
Worker::Worker() {
    // you could copy data from constructor arguments to internal variables here.
}
 
// --- DECONSTRUCTOR ---
Worker::~Worker() {
    // free resources
}
 
// --- PROCESS ---
// Start processing data.
void Worker::process() {
    // allocate resources using new here
    qDebug("Hello World!");
    emit finished();
}
