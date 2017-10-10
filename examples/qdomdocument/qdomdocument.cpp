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

    const auto firstChild = doc.firstChildElement();              // Returns <one> element and its recursive content.
    const auto firstChildOne = doc.firstChildElement("one");      // Returns <one> element and its recursive content.
    const auto firstChildTwo = doc.firstChildElement("two");      // DOES NOT WORK, returns ""
    const auto firstChildThree = doc.firstChildElement("three");  // DOES NOT WORK, returns ""

    qDebug() << toString(firstChild);
    qDebug() << toString(firstChildOne);
    qDebug() << toString(firstChildTwo);
    qDebug() << toString(firstChildThree);

    const auto one = doc.firstChildElement("one");
    const auto two = doc.firstChildElement("one").firstChildElement("two");
    const auto three = doc.firstChildElement("one").firstChildElement("two").firstChildElement("three");

    qDebug() << toString(one);
    qDebug() << toString(two);
    qDebug() << toString(three);

    const auto defaultConstructedDoc = QDomDocument();
    qDebug() << defaultConstructedDoc.isNull();
    
    doc.clear();
    qDebug() << doc.isNull();

    return a.exec();
}
