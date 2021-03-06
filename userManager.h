#pragma once

#include <set>
#include <map>
#include <vector>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include "user.h"

class userManager
{
public:
	userManager();
	~userManager();
	enum elementType
	{
		ID,
		USERNAME,
		PASSWORD,
		CONTACT,
		ADDRESS,
		BALANCE,
		STATUS,
		NONE
	};
	bool userRegister(QString username, QString password, QString contact, QString address);
	bool checkPassword(QString username, QString password);
	bool changeUserInfo(QString ID, int type, QString newValue);
	bool banUser(QString ID);
	bool compare(user u, QString qs, int type);
	std::vector<user> search(QString qs, int type);
	QString getNextID();
	user getUser(QString username);
	user getUserByID(QString ID);
	bool getAndModify(int searchType, QString searchElement, int modityType, QString modifyElement);

private:
	void readFile();
	void writeFile();
	std::set<user> data;
	std::map<QString, QString> keyring;
};
