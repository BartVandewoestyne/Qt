#include <QtCore>
#include <QDomNode>
#include <QtXml>
#include <QDebug>
#include <QString>
#include <QTextStream>

#include <cassert>

QString toString(const QDomNode& node)
{
    QString str;
    node.save(QTextStream(&str), 4);
    
    // Remove trailing whitespace and newlines.
    while (str.endsWith(' ')) str.chop(1);
    while (str.endsWith('\n')) str.chop(1);

    return str;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument doc;
    const auto contentOK = doc.setContent(QString(
        "<one>"
        "    <two>"
        "        <three/>"
        "    </two>"
        "</one>"
        ));
    assert(contentOK);

    qDebug() << "Converting a QDomDocument to a QString:";
    const int indent = -1;
    qDebug() << "=> Method 1: using doc.toString(indent)";
    qDebug() << doc.toString(indent);
    qDebug() << "=> Method 2: using QTextStream";
    QString str;
    QTextStream stream(&str);
    doc.save(stream, indent);
    qDebug() << str;


    qDebug() << "Finding child elements:";
    const auto firstChild = doc.firstChildElement();              // Returns <one> element and its recursive content.
    qDebug() << toString(firstChild);

    {
        qDebug() << "=> Test 1:";
        const auto one = doc.firstChildElement("one");      // Returns <one> element and its recursive content.
        const auto two = doc.firstChildElement("two");      // DOES NOT WORK, returns ""
        const auto three = doc.firstChildElement("three");  // DOES NOT WORK, returns ""
        qDebug() << toString(one);
        qDebug() << toString(two);
        qDebug() << toString(three);
    }

    {
        qDebug() << "=> Test 2:";
        const auto one = doc.firstChildElement("one");
        const auto two = doc.firstChildElement("one").firstChildElement("two");
        const auto three = doc.firstChildElement("one").firstChildElement("two").firstChildElement("three");
        qDebug() << toString(one);
        qDebug() << toString(two);
        qDebug() << toString(three);
    }

    qDebug() << "Appending a child element to a QDomDocument that already has one:";
    QDomDocument otherDoc;
    const auto success = otherDoc.setContent(QString("<Other/>")); 
    assert(success);

    doc.appendChild(otherDoc.firstChildElement());
    qDebug() << "After appending a child to a QDomDocument that already has a root element:";
    qDebug() << doc.toString();

    qDebug() << "After calling QDomDocument::clear(), doc.isNull() is:";
    doc.clear();
    qDebug() << doc.isNull();
    
    qDebug() << "Default constructed QDomDocument (isNull() test):";
    const auto defaultConstructedDoc = QDomDocument();
    qDebug() << defaultConstructedDoc.isNull();

    return a.exec();
}
