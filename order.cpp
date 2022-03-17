#include "order.h"

order::order(QStringList qsl)
{
	this->ID = qsl[0];
	this->commodityID = qsl[1];
	this->price = qsl[2].toDouble();
	this->quantity = qsl[3].toInt();
	this->tradeTime = qsl[4];
	this->sellerID = qsl[5];
	this->buyerID = qsl[6];
}

order::order(QString ID, QString commodityID, double price, int quantity, QString tradeTime, QString sellerID, QString buyerID)
{
	this->ID = ID;
	this->commodityID = commodityID;
	this->price = price;
	this->quantity = quantity;
	this->tradeTime = tradeTime;
	this->sellerID = sellerID;
	this->buyerID = buyerID;
}

bool order::operator<(const order b) const
{
	return this->ID < b.ID;
}
