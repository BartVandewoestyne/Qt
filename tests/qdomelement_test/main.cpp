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


void printIt(const QDomElement& element)
{
    QString s;
    QTextStream str(&s);
    element.save(str, 4);

    qDebug() << s;
}

void fillIt(QDomElement& element)
{
    QString content =
            "  <book>"
            "    <Title>MyBookTitle</Title>"
            "  </book>";

    QDomDocument doc;
    doc.setContent(content);

    element = doc.documentElement().firstChildElement();

    printIt(element);

}  // doc goes out of scope here...

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    {
        QDomElement element;

        fillIt(element);

        printIt(element);  // doc no longer exists, but is element still valid here
                           // because the DOM tree still exists???

    }  // Both doc and element are deleted here, so DOM tree also gets deleted???

    return 0;
}
