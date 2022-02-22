#pragma once

#include <vector>
#include <QFile>
#include <QTextStream>
#include "order.h"

class orderManager
{
public:
	orderManager();
	~orderManager();
	void readFile();
	void writeFile();

private:
	std::vector<order>data;
};

