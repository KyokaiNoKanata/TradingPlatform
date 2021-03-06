#pragma once

#include <vector>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include "order.h"

class orderManager
{
public:
	orderManager();
	~orderManager();
	enum elementType
	{
		ID,
		COMMODITY_ID,
		PRICE,
		QUANTITY,
		TRADE_TIME,
		SELLER_ID,
		BUYER_ID,
		NONE
	};
	void readFile();
	void writeFile();
	bool compare(order o, QString qs, int type);
	bool newOrder(QStringList qsl);
	std::vector<order> search(QString qs, int type);
	QString getNextID();

private:
	std::vector<order> data;
};
