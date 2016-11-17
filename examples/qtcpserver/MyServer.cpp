#include "MyServer.h"

#include <QDebug>
#include <QtCore>
#include <QTcpSocket>

MyServer::MyServer(QObject *parent)
    : QObject(parent)
{
    connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(handleNewConnection()));
    bool listening = tcpServer.listen(QHostAddress(QHostAddress::LocalHost), 4000);
}

void MyServer::handleNewConnection()
{
    pServerSocket = tcpServer.nextPendingConnection();
    connect(pServerSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(pServerSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    pServerSocket->write("Hello!");
}

void MyServer::startRead()
{
    while (pServerSocket->canReadLine())
    {
        QString line = pServerSocket->readLine();
        qDebug() << "Client echo: " << line;

        pServerSocket->write(QString("Server answer: I've taken your message.\n").toUtf8());
    }
}

void MyServer::disconnected()
{
    qDebug() << "disconnected() called";
}