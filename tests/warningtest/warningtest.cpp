/**
 * Illustrate how Qt disables some useful warnings.
 *
 * References:
 *
 *   [1] https://bugreports.qt.io/browse/QTBUG-26877
 *   [2] http://permalink.gmane.org/gmane.comp.lib.qt.devel/20707
 */

#include <QDebug>

int main()
{
    int x = 3.25;  // should give error on conversion from double to int with possible loss of data

    qDebug() << "x = " << x;
}
