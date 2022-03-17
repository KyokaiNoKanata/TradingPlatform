#pragma once

#include <QFile>
#include <QTextStream>
#include <vector>
#include <QDateTime>
#include "charge.h"

class chargeManager
{
public:
	chargeManager();
	~chargeManager();
	void addCharge(QString ID, double amount);
	std::vector<double>getData(QString ID);

private:
	QDateTime qdt;
	std::vector<charge>data;
	void readFile();
	void writeFile();
};

