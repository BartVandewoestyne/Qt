#ifndef MY_SERVER_H
#define MY_SERVER_H

#include <QTcpServer>

class MyServer : public QObject
{
    Q_OBJECT

public:
    MyServer(QObject* parent = 0);

private slots:
    void handleNewConnection();
    void startRead();
    void disconnected();

private:
    QTcpServer tcpServer;    
    QTcpSocket* pServerSocket;
};

#endif