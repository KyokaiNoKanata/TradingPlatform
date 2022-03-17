#pragma once

#include <set>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "commodity.h"

class commodityManager
{
public:
	commodityManager();
	~commodityManager();
	enum elementType { ID, NAME, PRICE, QUANTITY, INFORMATION, SELLER_ID, SHELF_TIME, STATUS, NONE };
	void readFile();
	void writeFile();
	bool newCommodity(QStringList qsl);
	bool compare(commodity c, QString qs, int type);
	std::vector<commodity>search(QString qs, int type);

private:
	QDateTime qdt;
	std::set<commodity>data;
};
