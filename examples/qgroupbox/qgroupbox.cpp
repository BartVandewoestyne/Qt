#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    
    QMainWindow* window = new QMainWindow();    
    
    QGroupBox* groupBox = new QGroupBox("Exclusive Radio Buttons");
    QRadioButton* radio1 = new QRadioButton("Radio button 1");
    QRadioButton* radio2 = new QRadioButton("Radio button 2");
    QRadioButton* radio3 = new QRadioButton("Radio button 3");
    radio1->setChecked(true);
    
    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    
    window->setCentralWidget(groupBox);
    window->show();

    return app.exec();
}
