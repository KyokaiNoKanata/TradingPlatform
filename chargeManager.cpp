#include "chargeManager.h"

chargeManager::chargeManager()
{
	readFile();
}

chargeManager::~chargeManager()
{
}

void chargeManager::addCharge(QString ID, double amount)
{
	readFile();
	QStringList qsl = {ID, QString::number(amount, 10, 1), qdt.currentDateTime().toString("yyyy-MM-dd")};
	charge c(qsl);
	data.push_back(c);
	writeFile();
}

std::vector<double> chargeManager::getData(QString ID)
{
	readFile();
	std::vector<double> res;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if ((*it).userID == ID)
		{
			res.push_back((*it).chargeAmount);
		}
	}
	return res;
}

void chargeManager::readFile()
{
	data.clear();
	QFile qf("data/charge.txt");
	qf.open(QIODevice::ReadOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	QString qs;
	QStringList qsl;
	qs = qts.readLine();
	while (!qts.atEnd())
	{
		qs = qts.readLine();
		qsl = qs.split(",");
		charge c(qsl);
		data.push_back(c);
	}
	qf.close();
}

void chargeManager::writeFile()
{
	QFile qf("data/charge.txt");
	qf.open(QIODevice::WriteOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	qts << QString("用户ID,充值金额,充值时间");
	for (auto it = data.begin(); it != data.end(); it++)
	{
		qts << '\n'
			<< (*it).userID << ',' << QString::number((*it).chargeAmount, 10, 1) << ',' << (*it).chargeTime;
	}
	qf.close();
}
