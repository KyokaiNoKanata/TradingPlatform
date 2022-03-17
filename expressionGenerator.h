#pragma once

#include <set>
#include "orderManager.h"
#include "chargeManager.h"

class expressionGenerator
{
public:
	expressionGenerator(QString ID);
	~expressionGenerator();
	QString generate();

private:
	QString ID;
	orderManager om;
	chargeManager cm;
	QString fromCharge();
	QString fromOrder();
};
