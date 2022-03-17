#pragma once

#include "commodityManager.h"
#include "orderManager.h"
#include "userManager.h"

class instructionDecoder
{
public:
	enum returnType { BOOL, COMMODITY, ORDER, USER };
	int getType(QString qs);
	bool modifyOperation(QString qs);
	std::vector<commodity>selectCommodity(QString qs);
	std::vector<order>selectOrder(QString qs);
	std::vector<user>selectUser(QString qs);

private:
	commodityManager cm;
	orderManager om;
	userManager um;
	int getCommodityElementType(QString qs);
	int getOrderElementType(QString qs);
	int getUserElementType(QString qs);
};
