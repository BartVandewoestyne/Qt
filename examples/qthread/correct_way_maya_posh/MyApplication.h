#ifndef MY_APPLICATION_H
#define MY_APPLICATION_H

#include <QObject>
#include <QString>

class MyApplication : public QObject {
    Q_OBJECT

public:
    void doIt();

public slots:
    void errorString(QString error);
};

#endif  // MY_APPLICATION_H