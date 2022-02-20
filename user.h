#pragma once

#include<QString>

class user
{
public:
	user(QString ID, QString username, QString password, QString contact, QString address, double balance, int status);
	QString ID;
	QString username;
	QString password;
	QString contact;
	QString address;
	double balance;
	int status;
	bool operator<(user b);
};

