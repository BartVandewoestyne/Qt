/**
 * QFileInfo example.
 */

#include <QDebug>
#include <QDir>
#include <QFileInfo>

int main()
{
    QFileInfo info1("../qcombobox_example.cpp");

    qDebug() << "absoluteFilePath(): " << info1.absoluteFilePath();
    qDebug() << "baseName(): " << info1.baseName();
    qDebug() << "fileName(): " << info1.fileName();
    qDebug() << "dir(): " << info1.dir();
    qDebug() << "size(): " << info1.size();
    qDebug() << "suffix(): " << info1.suffix();
}
