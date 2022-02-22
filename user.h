#pragma once

#include <QString>
#include <QStringList>

#define NORMAL 0
#define BANNED 1

class user
{
public:
	user(QStringList qsl);
	user(QString ID, QString username, QString password, QString contact, QString address, double balance, int status);
	QString ID;
	QString username;
	QString password;
	QString contact;
	QString address;
	double balance;
	bool status;
	bool operator<(const user& b)const;
};

