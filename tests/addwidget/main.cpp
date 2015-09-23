/*!
 * Test to see what happens if we add a widget twice at different
 * locations in a QGridLayout.
 */

#include <QApplication>
#include <QGridLayout>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QLabel* label1 = new QLabel("QLabel1");
    QLabel* label2 = new QLabel("QLabel2");

    QGridLayout* layout = new QGridLayout();

    // This works:
    layout->addWidget(label1, 0, 0);
    layout->addWidget(label2, 0, 1);

    // This doesn't work:
    //layout->addWidget(label1, 0, 0);
    //layout->addWidget(label1, 0, 1);

    QWidget* window = new QWidget();
    window->setLayout(layout);
    window->show();

    return app.exec();
}
