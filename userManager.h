#pragma once

#include<set>
#include<map>
#include<QFile>
#include<QTextStream>
#include "user.h"

class userManager
{
public:
	void readFile();
	void writeFile();

private:
	std::set<user>userData;
	std::map<QString, QString>keyring;
};

