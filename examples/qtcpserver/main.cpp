#include "MyServer.h"
#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
	
    MyServer server;

    return app.exec();
}