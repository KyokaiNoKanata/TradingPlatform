#include "orderManager.h"

orderManager::orderManager()
{
}

orderManager::~orderManager()
{
}

void orderManager::readFile()
{
	QFile qf("data/order.txt");
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
		order o(qsl);
		this->data.push_back(o);
	}
	qf.close();
}

void orderManager::writeFile()
{
}
