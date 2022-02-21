#include "commodityManager.h"

commodityManager::commodityManager()
{
}

commodityManager::~commodityManager()
{
}

void commodityManager::readFile()
{
	QFile qf("data/commodity.txt");
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
		commodity c(qsl);
		this->data.insert(c);
	}
	qf.close();
}

void commodityManager::writeFile()
{
}
