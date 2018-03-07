#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QString>

int main()
{
	{
		qDebug() << "Appending a single byte to a QByteArray:";
		QByteArray ba;
		ba.append('\x89');                      // THE ONLY GOOD WAY TO DO IT!
		//ba.append(0x89);                      // warning C4309: 'argument': truncation of constant value
		//ba.append(char(0x89));                // works, but old-style C-cast
		//ba.append(static_cast<char>(0x89));   // warning C4309: 'static_cast': truncation of constant value
		//ba.append(QByteArray::number(0x89));  // wrong data in QByteArray
		qDebug() << ba.toHex();
	}

	{
		qDebug() << "Appending two bytes to a QByteArray:";
		QByteArray ba;
		ba.append("\x89\x01");
		qDebug() << ba.toHex();
	}

	{
		qDebug() << "Appending constant of type std::uint16_t to a QByteArray:";
		const std::uint16_t FOO = 0x8901;
		QByteArray ba;
		QDataStream baStream(&ba, QIODevice::Append);
		baStream.setByteOrder(QDataStream::LittleEndian);
		baStream << FOO;
		qDebug() << ba.toHex();

		qDebug() << "TODO: mixing types:";
		ba.append('\x99');
		//baStream << static_cast<quint8>(0x88);
		qDebug() << ba.toHex();
	}
}
