/*!
 * Example illustrating the use of QMap.
 *
 * References:
 *
 *   [1] http://doc.qt.io/qt-4.8/qmap.html
 */

#include <QDebug>
#include <QMap>
#include <QString>


void showMap(const QMap<QString, int>& map)
{
    foreach (const QString& str, map.keys())
        qDebug() << str << ":" << map.value(str);
}


void showNum(int num)
{
    qDebug() << num;
}


int main()
{

    QMap<QString, int> map;

    map["one"] = 1;
    map["three"] = 3;
    map["seven"] = 7;

    map.insert("twelve", 12);

    showMap(map);

    int num1 = map["thirteen"];
    int num2 = map.value("thirteen");

    showNum(num1);
    showNum(num2);

    {
        int timeout = 30;
        if (map.contains("TIMEOUT"))
            timeout = map.value("TIMEOUT");
        showNum(timeout);
    }
    {
        int timeout = map.value("TIMEOUT", 30);
        showNum(timeout);
    }

    map.insert("plenty", 100);
    map.insert("plenty", 2000);
}
