/*!
 * References:
 *
 *   [1] https://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/
 *
 *  TODO: I'm not sure if this is correct yet.  I cannot see the two threads in Visual Studio 2012 when I debug this.
 */

#include "MyApplication.h"

#include <QCoreApplication>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    MyApplication myApp;
    myApp.doIt();

    return app.exec();
}
