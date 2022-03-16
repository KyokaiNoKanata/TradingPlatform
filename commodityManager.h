#pragma once

#include <set>
#include <vector>
#include <QFile>
#include <QTextStream>
#include "commodity.h"

class commodityManager
{
public:
	commodityManager();
	~commodityManager();
	enum elementType { ID, NAME, PRICE, QUANTITY, INFORMATION, SELLER_ID, SHELF_TIME, STATUS };
	void readFile();
	void writeFile();
	bool compare(commodity c, QString qs, int type);
	std::vector<commodity>search(commodity c, QString qs, int type);

private:
	std::set<commodity>data;
};
