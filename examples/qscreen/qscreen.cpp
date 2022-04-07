#include <QApplication>
#include <QScreen>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const auto screens = QApplication::screens();
    qDebug() << screens.size();
    for (const auto& screen : screens)
    {
        const auto geometry = screen->geometry();
        const auto screenName = screen->name();
        const auto width = geometry.width();
        const auto height = geometry.height();
        qDebug() << width << height;
    }
}
