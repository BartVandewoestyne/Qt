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

}
