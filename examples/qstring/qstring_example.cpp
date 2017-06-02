#include <QDebug>
#include <QString>

int main()
{
  qDebug() << QString().isNull();
  qDebug() << QString().isEmpty();

  qDebug() << QString("").isNull();
  qDebug() << QString("").isEmpty();

  qDebug() << QString("abc").isNull();
  qDebug() << QString("abc").isEmpty();

  // To create a null QString, you can just default initialize it.
  QString theNullString;
  qDebug() << "theNullString.isNull() = " << theNullString.isNull();
  qDebug() << "theNullString.isEmpty() = " << theNullString.isEmpty();

  // Don't do this ...
  qDebug() << QString("%1 %2 %3").arg(1).arg(2).arg(3);
  // ... but rather this (see http://doc.qt.io/qt-4.8/qstring.html#arg-2
  // and https://youtu.be/Ov7s0GgBbOQ?t=45m40s)
  qDebug() << QString("%1 %2 %3").arg(QString::number(1),
                                      QString::number(2),
                                      QString::number(3));

  QString str = "  foo bar   foo     ";
  qDebug() << "original string: |" << str << "|";
  str = str.trimmed();
  qDebug() << "after str.trimmed(): |" << str << "|";
}
