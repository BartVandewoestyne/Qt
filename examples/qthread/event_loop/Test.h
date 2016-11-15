#ifndef TEST_H
#define TEST_H

#include <QDebug>
#include <QEvent>
#include <QObject>
#include <QThread>

class Test : public QObject
{
    Q_OBJECT

protected:

    bool event(QEvent *evt)
    {
        if (evt->type() == QEvent::User) {
            qDebug() << "Event received in thread" << QThread::currentThread();
            return true;
        }
        return QObject::event(evt);
    }

};

#endif  // TEST_H
