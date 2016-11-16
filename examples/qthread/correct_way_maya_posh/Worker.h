#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QString>

class Worker : public QObject {
    Q_OBJECT
 
public:
    Worker();
    ~Worker();
 
public slots:
    void process();
 
signals:
    void finished();
    void error(QString err);
 
private:
    // add your variables here
};

#endif  // WORKER_H