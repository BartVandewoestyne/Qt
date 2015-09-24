/**
 * Example on how to read XML using Qt.
 *
 * References:
 *
 *   [1] http://www.bogotobogo.com/Qt/Qt5_QtXML_QDOM_Reading_XML.php
 */

#include <QtCore>
#include <QtXml>
#include <QDebug>

void retrievElements(QDomElement root, QString tag, QString att)
{
    QDomNodeList nodes = root.elementsByTagName(tag);

    qDebug() << "# nodes = " << nodes.count();
    for (int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if (elm.isElement())
        {
            QDomElement e = elm.toElement();
            qDebug() << e.attribute(att);
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create a document to write XML
    QDomDocument document;

    // Open a file for reading
    QFile file("dorms.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for reading.";
        return -1;
    }
    else
    {
        // loading
        if (!document.setContent(&file))
        {
            qDebug() << "Failed to load the file for reading.";
            return -1;
        }
        file.close();
    }

    // Getting root element
    QDomElement root = document.firstChildElement();

    // retrievelements(QDomElement root, QString tag, QString att)
    retrievElements(root, "Dorm", "Name");

    qDebug() << "Reading finished";

    return a.exec();
}
