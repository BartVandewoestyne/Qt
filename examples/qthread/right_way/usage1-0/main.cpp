/*!
 * References:
 *
 *   [1] http://blog.debao.me/2013/08/how-to-use-qthread-in-the-right-way-part-1/
 */

#include <QtCore>

class Thread : public QThread
{
private:
    void run()
    {
        qDebug() << "From worker thread: " << currentThreadId();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "From main thread: " << QThread::currentThreadId();

    Thread t;
    QObject::connect(&t, SIGNAL(finished()), &a, SLOT(quit()));

    t.start();
    return a.exec();
}
