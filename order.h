#pragma once

#include <QString>
#include <QStringList>

class order
{
public:
	order(QStringList qsl);
	order(QString orderID, QString commodityID, double price, int quantity, QString tradeTime, QString sellerID, QString buyerID);
	QString ID;
	QString commodityID;
	double price;
	int quantity;
	QString tradeTime;
	QString sellerID;
	QString buyerID;
	bool operator<(const order b)const;
};
