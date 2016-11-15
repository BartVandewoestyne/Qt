#ifndef BUTTON_H
#define BUTTON_H

#include "Test.h"

#include <QCoreApplication>
#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT

    Test *m_test;

public:

    Button(Test *test) : QPushButton("Send Event"), m_test(test)
    {
        connect(this, SIGNAL(clicked()), SLOT(onClicked()));
    }

private slots:

    void onClicked()
    {
        QCoreApplication::postEvent(m_test, new QEvent(QEvent::User));
    }

};

#endif  // BUTTON_H
