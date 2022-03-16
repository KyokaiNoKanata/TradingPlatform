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

std::vector<commodity> instructionDecoder::selectCommodity(QString qs)
{
	return std::vector<commodity>();
}

std::vector<order> instructionDecoder::selectOrder(QString qs)
{
	return std::vector<order>();
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
	return 0;
}

int instructionDecoder::getOrderElementType(QString qs)
{
	return 0;
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
