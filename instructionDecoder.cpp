#include "instructionDecoder.h"

int instructionDecoder::getType(QString qs)
{
	QStringList qsl = qs.split(" ");
	if (qsl[0] == "SELECT")
	{
		if (qsl[3] == "commodity")
		{
			return COMMODITY;
		}
		else if (qsl[3] == "order")
		{
			return ORDER;
		}
		else if (qsl[3] == "user")
		{
			return USER;
		}
	}
	else
	{
		return BOOL;
	}
}

bool instructionDecoder::modifyOperation(QString qs)
{
	QStringList qsl = qs.split(" ");
	if (qsl[0] == "INSERT")
	{
		QStringList qsl2 = qsl[4].remove("(").remove(")").split(",");
		if (qsl[2] == "commodity")
		{
			return cm.newCommodity(qsl2);
		}
		else if (qsl[2] == "order")
		{
			return om.newOrder(qsl2);
		}
		else if (qsl[2] == "user")
		{
			return um.userRegister(qsl2[1], qsl2[2], qsl2[3], qsl2[4]);
		}
		else
		{
			return false;
		}
	}
	else if (qsl[0] == "UPDATE")
	{
		int searchType;
		int modifyType;
		QString searchElement = qsl[9];
		QString modifyElement = qsl[5];
		if (qsl[1] == "commodity")
		{
			searchType = getCommodityElementType(qsl[7]);
			modifyType = getCommodityElementType(qsl[3]);
			return cm.getAndModify(searchType, searchElement, modifyType, modifyElement);
		}
		else if (qsl[1] == "order")
		{
			return false;
		}
		else if (qsl[1] == "user")
		{
			searchType = getUserElementType(qsl[7]);
			modifyType = getUserElementType(qsl[3]);
			return um.getAndModify(searchType, searchElement, modifyType, modifyElement);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

std::vector<commodity> instructionDecoder::selectCommodity(QString qs)
{
	QStringList qsl = qs.split(" ");
	if (qsl.size() == 4)
	{
		return cm.search(QString(), commodityManager::NONE);
	}
	else
	{
		int type = getCommodityElementType(qsl[5]);
		return cm.search(qsl[7], type);
	}
}

std::vector<order> instructionDecoder::selectOrder(QString qs)
{
	QStringList qsl = qs.split(" ");
	if (qsl.size() == 4)
	{
		return om.search(QString(), userManager::NONE);
	}
	else
	{
		int type = getOrderElementType(qsl[5]);
		return om.search(qsl[7], type);
	}
}

std::vector<user> instructionDecoder::selectUser(QString qs)
{
	QStringList qsl = qs.split(" ");
	if (qsl.size() == 4)
	{
		return um.search(QString(), userManager::NONE);
	}
	else
	{
		int type = getUserElementType(qsl[5]);
		return um.search(qsl[7], type);
	}
}

int instructionDecoder::getCommodityElementType(QString qs)
{
	if (qs == "ID")
	{
		return commodityManager::ID;
	}
	else if (qs == "name")
	{
		return commodityManager::NAME;
	}
	else if (qs == "price")
	{
		return commodityManager::PRICE;
	}
	else if (qs == "quantity")
	{
		return commodityManager::QUANTITY;
	}
	else if (qs == "information")
	{
		return commodityManager::INFORMATION;
	}
	else if (qs == "sellerID")
	{
		return commodityManager::SELLER_ID;
	}
	else if (qs == "shelfTime")
	{
		return commodityManager::SHELF_TIME;
	}
	else if (qs == "status")
	{
		return commodityManager::STATUS;
	}
	else
	{
		return userManager::NONE;
	}
}

int instructionDecoder::getOrderElementType(QString qs)
{
	if (qs == "ID")
	{
		return orderManager::ID;
	}
	else if (qs == "commodityID")
	{
		return orderManager::COMMODITY_ID;
	}
	else if (qs == "price")
	{
		return orderManager::PRICE;
	}
	else if (qs == "quantity")
	{
		return orderManager::QUANTITY;
	}
	else if (qs == "tradeTime")
	{
		return orderManager::TRADE_TIME;
	}
	else if (qs == "sellerID")
	{
		return orderManager::SELLER_ID;
	}
	else if (qs == "buyerID")
	{
		return orderManager::BUYER_ID;
	}
	else
	{
		return orderManager::NONE;
	}
}

int instructionDecoder::getUserElementType(QString qs)
{
	if (qs == "ID")
	{
		return userManager::ID;
	}
	else if (qs == "username")
	{
		return userManager::USERNAME;
	}
	else if (qs == "password")
	{
		return userManager::PASSWORD;
	}
	else if (qs == "contact")
	{
		return userManager::CONTACT;
	}
	else if (qs == "address")
	{
		return userManager::ADDRESS;
	}
	else if (qs == "balance")
	{
		return userManager::BALANCE;
	}
	else if (qs == "status")
	{
		return userManager::STATUS;
	}
	else
	{
		return userManager::NONE;
	}
}
