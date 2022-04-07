#include <QDebug>
#include <QDomElement>

int main(int argc, char *argv[])
{
    QDomElement e;
    qDebug() << e.nodeName();
}
