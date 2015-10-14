#include <QDebug>

int main()
{

#ifdef Q_OS_WIN32
  qDebug() << "We are on Windows :-(";
#else
  qDebug() << "We are NOT on Windows :-)";
#endif

}
