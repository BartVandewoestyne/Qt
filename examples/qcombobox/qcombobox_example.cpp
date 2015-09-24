/**
 * QComboBox example.
 *
 * References:
 *
 *   [1] www.codeprogress.com/cpp/libraries/qt/QComboBoxHandleSelectionChange.php
 */
#include <QtGui>

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow();

    window->setWindowTitle(QString::fromUtf8("QComboBox example"));
    window->resize(330, 220);

    QWidget *centralWidget = new QWidget(window);
    QHBoxLayout *layout = new QHBoxLayout();
    centralWidget->setLayout(layout);

    QComboBox* comboBox = new QComboBox(centralWidget);
    comboBox->addItem("Item 1");
    comboBox->addItem("Item 2");
    comboBox->addItem("Item 3");

    layout->addWidget(comboBox);

    window->setCentralWidget(centralWidget);
    window->show();

    return app.exec();
}
