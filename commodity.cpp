#include "commodity.h"

commodity::commodity(QStringList qsl)
{
	this->ID = qsl[0];
	this->name = qsl[1];
	this->quantity = qsl[2].toInt();
	this->information = qsl[3];
	this->sellerID = qsl[4];
	this->shelfTime = qsl[5];
	this->status = qsl[6].toInt();
}

commodity::commodity(QString ID, QString name, QString price, int quantity, QString information, QString sellerID, QString shelfTime, int status)
{
	this->ID = ID;
	this->name = name;
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
