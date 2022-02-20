#include "commodity.h"

commodity::commodity(QString ID, QString name, QString price, QString quantity, QString information, QString sellerID, QString shelfTime, int status)
{
	this->ID = ID;
	this->name = name;
	this->quantity = quantity;
	this->information = information;
	this->sellerID = sellerID;
	this->shelfTime = shelfTime;
	this->status = status;
}

bool commodity::operator<(commodity b)
{
	return this->ID < b.ID;
}
