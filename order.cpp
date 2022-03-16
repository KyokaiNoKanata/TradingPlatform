#include "order.h"

order::order(QStringList qsl)
{
	this->ID = qsl[0];
	this->commodityID = qsl[0];
	this->price = qsl[0].toDouble();
	this->quantity = qsl[0].toInt();
	this->tradeTime = qsl[0];
	this->sellerID = qsl[0];
	this->buyerID = qsl[0];
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
