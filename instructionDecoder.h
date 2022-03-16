#pragma once

#include "commodityManager.h"
#include "orderManager.h"
#include "userManager.h"

class instructionDecoder
{
public:
	enum returnType { BOOL, COMMODITY, ORDER, USER };
	int getType(QString qs);
	std::vector<commodity>select(QString qs, commodity c);
	std::vector<order>select(QString qs, order o);
	std::vector<user>select(QString qs, user u);

private:
	commodityManager cm;
	orderManager om;
	userManager um;
};

