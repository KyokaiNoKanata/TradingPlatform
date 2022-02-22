#pragma once

#include <set>
#include <map>
#include <QFile>
#include <QTextStream>
#include "user.h"

class userManager
{
public:
	userManager();
	~userManager();
	void readFile();
	void writeFile();
	bool userRegister(QString username, QString password, QString contact, QString address);
	bool checkPassword(QString username, QString password);

private:
	std::set<user>data;
	std::map<QString, QString>keyring;
};

