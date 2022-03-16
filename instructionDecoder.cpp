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

std::vector<commodity> instructionDecoder::select(QString qs, commodity c)
{
	return std::vector<commodity>();
}

std::vector<order> instructionDecoder::select(QString qs, order o)
{
	return std::vector<order>();
}

std::vector<user> instructionDecoder::select(QString qs, user u)
{
	return std::vector<user>();
}
