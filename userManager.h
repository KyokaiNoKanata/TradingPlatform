#pragma once

#include<set>
#include<map>
#include<QFile>
#include<QTextStream>
#include "user.h"

class userManager
{
public:
	userManager();
	~userManager();
	void readFile();
	void writeFile();
	bool checkPassword(QString username, QString password);

private:
	std::set<user>userData;
	std::map<QString, QString>keyring;
};

