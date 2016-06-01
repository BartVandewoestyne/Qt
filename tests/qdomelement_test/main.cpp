/*
 * Test program that tries to answer the question:
 *
 *   "What happens to QDomElements from a QDomDocument
 *    after their QDomDocument goes out of scope?"
 *
 * References:
 *   [1] http://doc.qt.io/qt-4.8/qdomdocument.html
 */
#include <QApplication>
#include <QDebug>
#include <QDomDocument>
#include <QDomElement>
#include <QString>
#include <QTextStream>


QString toString(const QDomElement& element)
{
    QString s;
    QTextStream str(&s);
    element.save(str, 4);

    return s;
}

void fillIt(QDomElement& element)
{
    QString content =
            "<bookstore>"
            "  <book>"
            "    <Title>MyBookTitle</Title>"
            "  </book>"
            "</bookstore>";

    QDomDocument doc;
    doc.setContent(content);

    element = doc.documentElement().firstChildElement();

    qDebug() << "\nInside fillIt():";
    qDebug() << "\n  element is:\n" << toString(element);
    qDebug() << "\n  element.ownerDocument().toString(4) is:\n" << element.ownerDocument().toString(4);

}  // doc goes out of scope here...

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QDomElement element;

    qDebug() << "\nBefore fillIt():";
    qDebug() << "\n  element is:\n" << toString(element);
    qDebug() << "\n  element.ownerDocument().toString(4) is:\n" << element.ownerDocument().toString(4);

    fillIt(element);

    qDebug() << "\nAfter fillIt():";   
    qDebug() << "\n  element is:\n" << toString(element);  // doc no longer exists, but is element still valid here???
    qDebug() << "\n  element.ownerDocument().toString(4) is:\n" << element.ownerDocument().toString(4);

    return 0;
}
