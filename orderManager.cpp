#include "orderManager.h"

orderManager::orderManager()
{
	readFile();
}

orderManager::~orderManager()
{
	writeFile();
}

void orderManager::readFile()
{
	data.clear();
	QFile qf("data/order.txt");
	qf.open(QIODevice::ReadOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	QString qs;
	QStringList qsl;
	qs = qts.readLine();
	while (!qts.atEnd())
	{
		qs = qts.readLine();
		qsl = qs.split(",");
		order o(qsl);
		data.push_back(o);
	}
	qf.close();
}

void orderManager::writeFile()
{
	QFile qf("data/order.txt");
	qf.open(QIODevice::WriteOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	qts << QString("订单ID,商品ID,交易单价,数量,交易时间,卖家ID,买家ID");
	for (auto it = data.begin(); it != data.end(); it++)
	{
		qts << '\n'
			<< (*it).ID << ',' << (*it).commodityID << ',' << QString::number((*it).price, 10, 1) << ',' << (*it).quantity << ',' << (*it).tradeTime << ',' << (*it).sellerID << ',' << (*it).buyerID;
	}
	qf.close();
}

bool orderManager::compare(order o, QString qs, int type)
{
	switch (type)
	{
	case ID:
		return o.ID.contains(qs);
	case COMMODITY_ID:
		return o.commodityID.contains(qs);
	case PRICE:
		return o.price == qs.toDouble();
	case QUANTITY:
		return o.quantity == qs.toInt();
	case TRADE_TIME:
		return o.tradeTime.contains(qs);
	case SELLER_ID:
		return o.sellerID.contains(qs);
	case BUYER_ID:
		return o.buyerID.contains(qs);
	default:
		return true;
	}
}

bool orderManager::newOrder(QStringList qsl)
{
	order o(qsl);
	data.push_back(o);
	writeFile();
	return true;
}

std::vector<order> orderManager::search(QString qs, int type)
{
	readFile();
	std::vector<order> res;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if (compare(*it, qs, type))
		{
			res.push_back(*it);
		}
	}
	return res;
}

QString orderManager::getNextID()
{
	QString ID = "T";
	auto temp = data.size() + 1;
	if (temp < 10)
	{
		ID += "00";
	}
	else if (temp < 100)
	{
		ID += "0";
	}
	ID += QString::number(temp);
	return ID;
}
