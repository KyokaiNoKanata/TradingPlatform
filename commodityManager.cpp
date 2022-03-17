#include "commodityManager.h"

commodityManager::commodityManager()
{
	readFile();
}

commodityManager::~commodityManager()
{
}

void commodityManager::readFile()
{
	data.clear();
	QFile qf("data/commodity.txt");
	qf.open(QIODeviceBase::ReadOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	QString qs;
	QStringList qsl;
	qs = qts.readLine();
	while (!qts.atEnd())
	{
		qs = qts.readLine();
		qsl = qs.split(",");
		commodity c(qsl);
		data.insert(c);
	}
	qf.close();
}

void commodityManager::writeFile()
{
	QFile qf("data/user.txt");
	qf.open(QIODevice::WriteOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	qts << "商品ID,名称,价格,数量,描述,卖家ID,上架时间,商品状态";
	QString temp;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if ((*it).status == commodity::NORMAL)
		{
			temp = "销售中";
		}
		else
		{
			temp = "已下架";
		}
		qts << '\n' << (*it).ID << ',' << (*it).name << ',' << QString::number((*it).price, 10, 1) << ',' << (*it).quantity << ',' << (*it).information << ',' << (*it).sellerID << ',' << (*it).shelfTime << ',' << temp;
	}
	qf.close();
}

bool commodityManager::compare(commodity c, QString qs, int type)
{
	switch (type)
	{
	case ID:
		return c.ID.contains(qs);
	case NAME:
		return c.name.contains(qs);
	case PRICE:
		return c.price == qs.toDouble();
	case QUANTITY:
		return c.quantity == qs.toInt();
	case INFORMATION:
		return c.information.contains(qs);
	case SELLER_ID:
		return c.sellerID.contains(qs);
	case SHELF_TIME:
		return c.shelfTime.contains(qs);
	case STATUS:
		return c.status == qs.toInt();
	default:
		return true;
	}
}

std::vector<commodity> commodityManager::search(QString qs, int type)
{
	readFile();
	std::vector<commodity>res;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if (compare(*it, qs, type))
		{
			res.push_back(*it);
		}
	}
	return res;
}
