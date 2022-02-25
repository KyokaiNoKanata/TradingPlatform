#include "userManager.h"

userManager::userManager()
{
	readFile();
}

userManager::~userManager()
{
}

void userManager::readFile()
{
	QFile qf("data/user.txt");
	qf.open(QIODeviceBase::ReadOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	QString qs;
	QStringList qsl;
	qs = qts.readLine();
	while (!qts.atEnd())
	{
		qs = qts.readLine();
		qsl = qs.split(",");
		user u(qsl);
		this->data.insert(u);
		this->keyring[u.username] = u.password;
	}
	qf.close();
}

void userManager::writeFile()
{
}

bool userManager::userRegister(QString username, QString password, QString contact, QString address)
{
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if ((*it).username == username)
		{
			return false;
		}
	}
	QString ID = "U" + QString::number(data.size() + 1);
	user u(ID, username, password, contact, address, 0, user::NORMAL);
	data.insert(u);
	keyring[u.username] = u.password;
	writeFile();
	return true;
}

bool userManager::checkPassword(QString username, QString password)
{
	readFile();
	return keyring[username] == password;
}
