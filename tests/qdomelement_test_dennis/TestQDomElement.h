
#pragma once

#include <QWaitCondition>
#include <QMutex>
#include <iostream>
#include <QDateTime>
#include <QDomDocument>
#include <QDomElement>
#include <qtextstream.h>

extern QMutex gTestMutex;
extern QWaitCondition gTestWaitCondition;
extern QString gContent;

class TestQDomElement : public QObject
{
    Q_OBJECT

    public slots:
        void startTestQDomElement()
        {
			QDomElement actionElement;
			QDomElement resultElement;
			QDomElement errorElement;

			processAnswer(actionElement, resultElement, errorElement);
			printIt(actionElement, resultElement, errorElement);
			testElement(actionElement);
        }

	private:
		void processAnswer(QDomElement& actionElement, QDomElement& resultElement, QDomElement& errorElement)
		{
			gTestMutex.lock();
            std::cout << (QString("%1 waiting on waitCondition (timeout in 7 seconds).").arg(QDateTime::currentDateTime().toString())).toUtf8().constData() << std::endl;
            bool retVal = gTestWaitCondition.wait(&gTestMutex, 7000);
            if (!retVal)
            {
                std::cout << (QString("%1 WaitCondition timeout !").arg(QDateTime::currentDateTime().toString())).toUtf8().constData() << std::endl;
            }
			fillIt(actionElement, resultElement, errorElement);
			createStackData();
            gTestMutex.unlock();
		}

		void printIt(const QDomElement& actionElement, const QDomElement& resultElement, const QDomElement& errorElement)
		{
			QString s;
			QTextStream str(&s);

			std::cout << std::endl << "*** START PRINT DATA ***" << std::endl;

			actionElement.save(str, 0);
			std::cout << s.toUtf8().constData() << std::endl;

			s.clear();
			resultElement.save(str, 0);
			std::cout << s.toUtf8().constData() << std::endl;

			s.clear();
			errorElement.save(str, 0);
			std::cout << s.toUtf8().constData() << std::endl;

			QString errorDescription = errorElement.attribute("description", "no error");
			std::cout << errorDescription.toUtf8().constData() << std::endl;

			std::cout << "*** END PRINT DATA ***" << std::endl << std::endl;
		}

		void fillIt(QDomElement& actionElement, QDomElement& resultElement, QDomElement& errorElement)
		{			
			QDomDocument doc;
			doc.setContent(gContent);

			actionElement = doc.documentElement().firstChildElement("Action");
			resultElement = doc.documentElement().firstChildElement("Result");
			errorElement = doc.documentElement().firstChildElement("Error");

			testElement(actionElement);
		}  // doc goes out of scope here...

		void createStackData()
		{
			gContent =
					"  <hello>"
					"    <tag1>zomaar iets</tag1>"
					"	 <tag2  yes='true' />"
					"	 <tag3 doit />"
					"  </hello>";
			QDomDocument doc;
			doc.setContent(gContent);

			QDomElement tag1Element = doc.documentElement().firstChildElement("tag1");
			QDomElement tag2Element = doc.documentElement().firstChildElement("tag2");
			QDomElement tag3Element = doc.documentElement().firstChildElement("tag3");
		}

		void testElement(const QDomElement& elem)
		{
			QDomNode parentElem = elem.parentNode();
			QDomNode childElem = elem.firstChild();

			std::cout << std::endl << "Test element: " << elem.nodeName().toUtf8().constData() << std::endl;
			if (parentElem.isNull())
			{
				std::cout << "Parent element is NULL !" << std::endl;
			}
			else
			{
				std::cout << "Test parent element: " << parentElem.nodeName().toUtf8().constData() << std::endl;
			}
			if (childElem.isNull())
			{
				std::cout << "Child element is NULL !" << std::endl;
			}
			else
			{
				std::cout << "Test Child element: " << childElem.nodeName().toUtf8().constData() << std::endl;
			}

		}
};
