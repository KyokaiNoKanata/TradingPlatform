#include "user.h"

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

bool user::operator<(user b)
{
	return this->ID < b.ID;
}
