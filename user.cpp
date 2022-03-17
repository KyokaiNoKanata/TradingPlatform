#include "user.h"

user::user(QStringList qsl)
{
	this->ID = qsl[0];
	this->username = qsl[1];
	this->password = qsl[2];
	this->contact = qsl[3];
	this->address = qsl[4];
	this->balance = qsl[5].toDouble();
	this->status = qsl[6].toInt();
}

user::user(QString ID, QString username, QString password, QString contact, QString address, double balance, int status)
{
	this->ID = ID;
	this->username = username;
	this->password = password;
	this->contact = contact;
	this->address = address;
	this->balance = balance;
	this->status = status;
}

bool user::operator<(const user& b)const
{
	return this->ID < b.ID;
}
