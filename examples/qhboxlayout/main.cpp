#include <QApplication>
#include <QGroupBox>
#include <QHBoxLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget* window = new QWidget();

    QGroupBox* groupBox1 = new QGroupBox("My GroupBox 1");
    QGroupBox* groupBox2 = new QGroupBox("My GroupBox 2");

    QHBoxLayout* hlayout = new QHBoxLayout;

    hlayout->addWidget(groupBox1);
    hlayout->addWidget(groupBox2);

    window->setLayout(hlayout);

    window->show();
    return app.exec();
}
