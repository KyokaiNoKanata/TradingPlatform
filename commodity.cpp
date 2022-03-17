#include "commodity.h"

commodity::commodity(QStringList qsl)
{
	this->ID = qsl[0];
	this->name = qsl[1];
	this->price = qsl[2].toDouble();
	this->quantity = qsl[3].toInt();
	this->information = qsl[4];
	this->sellerID = qsl[5];
	this->shelfTime = qsl[6];
	this->status = qsl[7] == "销售中" ? NORMAL : BANNED;
}

commodity::commodity(QString ID, QString name, double price, int quantity, QString information, QString sellerID, QString shelfTime, int status)
{
	this->ID = ID;
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->information = information;
	this->sellerID = sellerID;
	this->shelfTime = shelfTime;
	this->status = status;
}

bool commodity::operator<(commodity b)const
{
	return this->ID < b.ID;
}
