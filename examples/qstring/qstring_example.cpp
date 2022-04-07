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

  QString name("Bart");
  name.clear();
  qDebug() << name.isNull();
  qDebug() << name.isEmpty();
  name.clear();
  qDebug() << "After clearing:";
  qDebug() << name.isNull();
  qDebug() << name.isEmpty();

  const auto defaultConstructedQString = QString();
  qDebug() << "After default construction:";
  qDebug() << defaultConstructedQString.isNull();
  qDebug() << defaultConstructedQString.isEmpty();

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

  QString str1 = "0014";
  bool ok1;
  short hex1 = str1.toShort(&ok1, 16);
  
  QString str2 = "FFFE";
  bool ok2;
  short hex2 = static_cast<short>(str2.toUShort(&ok2, 16));

  const QByteArray ba = QByteArray::fromHex("21890100000a");
  const QByteArray prettyba = QByteArray(ba).replace("\n", "\\n").replace("\r", "\\r").replace('\0', "\\0");
  qDebug() << QString("%1").arg(ba.constData());
  qDebug() << QString("%1").arg(prettyba.constData());

  const auto nbDecimals = 3;
  const auto value = 1.234;
  QString toFillBad;
  toFillBad.sprintf("%.*f ", nbDecimals, value);
  const auto toFillGood1 = QString::number(value, 'f', nbDecimals) + " ";
  const auto toFillGood2 = QString("%1 ").arg(value, 0, 'f', nbDecimals);
  qDebug() << "toFillBad   = " << toFillBad;
  qDebug() << "toFillGood1 = " << toFillGood1;
  qDebug() << "toFillGood2 = " << toFillGood2;
}
