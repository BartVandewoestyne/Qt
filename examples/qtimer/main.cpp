/*!
 * References:
 *
 *   [1] http://www.bogotobogo.com/Qt/Qt5_QTimer.php
 */

#include <QCoreApplication>
#include "mytimer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    // Create MyTimer instance
    // QTimer object will be created in the MyTimer constructor
    MyTimer timer;

    return a.exec();
}
