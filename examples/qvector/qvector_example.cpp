#include <QDebug>
#include <QVector>

int main()
{
    // Correct
    {
        QVector<int> v(5);
        for (int i = 0; i < 5; ++i)
        {
            qDebug() << i;
            v[i] = i;
        }
    }

    // Wrong
    {
        QVector<int> v;
        for (int i = 0; i < 5; ++i)
        {
            qDebug() << i;
            v[i] = i;
        }
    }
}
