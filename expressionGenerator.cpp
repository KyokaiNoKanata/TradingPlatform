#include "expressionGenerator.h"

expressionGenerator::expressionGenerator(QString ID)
{
	this->ID = ID;
}

expressionGenerator::~expressionGenerator()
{
}

QString expressionGenerator::generate()
{
	QString qs1 = fromCharge(),
		qs2 = fromOrder();
	if (!qs1.isEmpty() && !qs2.isEmpty() && qs2[0] != '-')
	{
		return qs1 + "+" + qs2;
	}
	else if (qs1.isEmpty() && qs2.isEmpty())
	{
		return "0";
	}
	else
	{
		return qs1 + qs2;
	}
}

QString expressionGenerator::fromCharge()
{
	std::vector<double>data = cm.getData(ID);
	QString res;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if (it != data.begin())
		{
			res.append(" + ");
		}
		res.append(QString::number(*it, 10, 1));
	}
	return res;
}

QString expressionGenerator::fromOrder()
{
	QString res;
	std::vector<double>vd;
	std::vector<int>vi;
	std::set<int>si;
	std::vector<order>sellData = om.search(ID, orderManager::SELLER_ID);
	for (auto it = sellData.begin(); it != sellData.end(); it++)
	{
		vd.push_back((*it).price);
		vi.push_back((*it).quantity);
		si.insert((*it).quantity);
	}
	std::vector<order>buyData = om.search(ID, orderManager::BUYER_ID);
	for (auto it = buyData.begin(); it != buyData.end(); it++)
	{
		vd.push_back(-(*it).price);
		vi.push_back((*it).quantity);
		si.insert((*it).quantity);
	}
	for (auto it = si.begin(); it != si.end(); it++)
	{
		QString temp;
		for (int i = 0; i < vd.size(); i++)
		{
			if (vi[i] == *it)
			{
				if (!temp.isEmpty() && vd[i] >= 0)
				{
					temp.append("+");
				}
				temp.append(QString::number(vd[i], 10, 1));
			}
		}
		if (*it != 1)
		{
			if (!res.isEmpty())
			{
				res.append("+");
			}
			res.append("(");
			temp.append(")*" + QString::number(*it));
		}
		else
		{
			if (!res.isEmpty() && res[0] != '-')
			{
				res.append("+");
			}
		}
		res.append(temp);
	}
	return res;
}
