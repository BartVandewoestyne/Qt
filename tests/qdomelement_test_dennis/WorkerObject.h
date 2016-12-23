
#pragma once

#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <iostream>
#include <QDateTime>
#include <QWaitCondition>

extern QMutex gTestMutex;
extern QWaitCondition gTestWaitCondition;
extern QString gContent;

class WorkerObject : public QThread
{
    Q_OBJECT

public slots:
    void PerformLongRunningTask() 
    {
        QMutexLocker lock(&gTestMutex);
        std::cout << (QString("%1 TestMutex locked for 2 seconds by workerObject.").arg(QDateTime::currentDateTime().toString())).toUtf8().constData() << std::endl;
        this->msleep(2000);

		gContent =
					"  <notify>"
					"    <Action><Command>setProperty</Command></Action>"
					"	 <Result actionExecuted='false' />"
					"	 <Error description='random errordescription' />"
					"  </notify>";

        std::cout << (QString("%1 TestMutex released by workerObject.").arg(QDateTime::currentDateTime().toString())).toUtf8().constData() << std::endl;
		gTestWaitCondition.wakeAll();
    }
};

    
