#include <QDebug>
#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT

private slots:

    void onTimeout()
    {
        qDebug() << "Worker::onTimeout() called thread " << QThread::currentThreadId();
    }

};
