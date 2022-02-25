#pragma once

#include <set>
#include <QFile>
#include <QTextStream>
#include "commodity.h"

class commodityManager
{
public:
	commodityManager();
	~commodityManager();
	void readFile();
	void writeFile();

private:
	std::set<commodity>data;
};
