#include <QtCore>
#include <QThread>
#include <iostream>
#include <QMutex>
#include <QTimer>
#include <QDateTime>
#include "TestQDomElement.h"
#include "WorkerObject.h"
#include <QDomDocument>
#include <QDomElement>
#include <QString>
#include <QTextStream>

QMutex gTestMutex;
QWaitCondition gTestWaitCondition;
QString gContent;

int main(int argc, char **argv)
{
    QCoreApplication app (argc, argv);
    WorkerObject workerObject;
    TestQDomElement waitCondObject;

	QDomElement actionElement;
	QDomElement resultElement;
	QDomElement errorElement;

    std::cout << (QString("%1 Creating workThread 1.").arg(QDateTime::currentDateTime().toString())).toUtf8().constData() << std::endl;	
    QThread m_workThread1;
    waitCondObject.moveToThread(&m_workThread1);
    std::cout << (QString("%1 Creating workThread 2.").arg(QDateTime::currentDateTime().toString())).toUtf8().constData() << std::endl;
    QThread m_workThread2;
    workerObject.moveToThread(&m_workThread2);

    m_workThread1.start();
    m_workThread2.start();

    //Singleshot only works as soon as messageloop is started
    std::cout << (QString("%1 Starting startTestQDomElement").arg(QDateTime::currentDateTime().toString())).toUtf8().constData() << std::endl;
    QTimer::singleShot(0, &waitCondObject, SLOT(startTestQDomElement()));

    std::cout << (QString("%1 Scheduling PerformLongRunningTask in 2 seconds.").arg(QDateTime::currentDateTime().toString())).toUtf8().constData() << std::endl;
    QTimer::singleShot(2000, &workerObject, SLOT(PerformLongRunningTask()));

    return app.exec();
}
