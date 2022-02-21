#include "userManager.h"

userManager::userManager()
{
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

bool userManager::checkPassword(QString username, QString password)
{
	return this->keyring[username] == password;
}
