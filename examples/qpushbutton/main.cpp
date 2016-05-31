#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget* window = new QWidget();

    QPushButton* button1 = new QPushButton("QPushButton 1");
    button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton* button2 = new QPushButton("QPushButton 2");
    button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    QHBoxLayout* hlayout = new QHBoxLayout;
    hlayout->addWidget(button1);
    hlayout->addWidget(button2);

    window->setLayout(hlayout);

    window->show();
    return app.exec();
}
