#pragma once

#include <set>
#include <map>
#include <vector>
#include <QFile>
#include <QTextStream>
#include "user.h"

class userManager
{
public:
	userManager();
	~userManager();
	enum elementType { USERNAME, PASSWORD, CONTACT, ADDRESS };
	bool userRegister(QString username, QString password, QString contact, QString address);
	bool checkPassword(QString username, QString password);
	bool changeUserInfo(QString ID, int type, QString newValue);
	bool banUser(QString ID);
	std::vector<user>instrctionDecode(QString qs);

private:
	void readFile();
	void writeFile();
	std::set<user>data;
	std::map<QString, QString>keyring;
};
