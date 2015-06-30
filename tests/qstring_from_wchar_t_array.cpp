/*
 * Sample program to see the difference between QString::fromUtf16 and
 * QString::fromWCharArray.
 */

#include <QDebug>
#include <QString>

int main()
{
    const wchar_t *text = L"FooBar";

    QString s1 = QString::fromUtf16(reinterpret_cast<const ushort*>(text));
    QString s2 = QString::fromWCharArray(text);

    qDebug() << "sizeof(wchar_t) = " << sizeof(wchar_t);
    qDebug() << "QString::fromUtf16(reinterpret_cast<const ushort*>(text)) =>" << s1;
    qDebug() << "QString::fromWCharArray(text) =>" << s2;
}
