#include "userManager.h"

void userManager::readFile()
{
	QFile qf("data/uset.txt");
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	QString qs;
	QStringList qsl;
	while (!qts.atEnd())
	{
		qs = qts.readLine();
		qsl = qs.split(",");
		user u(qsl);
		userData.insert(u);
		keyring[u.username] = u.password;
	}
	qf.close();
}

void userManager::writeFile()
{
}
