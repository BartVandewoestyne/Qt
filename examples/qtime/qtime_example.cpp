#include <QDebug>
#include <QTime>

#include <chrono>
#include <thread>

int main()
{
    QTime startTime = QTime::currentTime();
    //QTime::currentTime();
    //startTime.start();  # Note sure if this is necessary here...

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    qDebug() << startTime.elapsed();
}
