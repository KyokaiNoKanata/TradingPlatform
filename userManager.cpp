﻿#include "userManager.h"

userManager::userManager()
{
	readFile();
}

userManager::~userManager()
{
}

void userManager::readFile()
{
	data.clear();
	QFile qf("data/user.txt");
	qf.open(QIODevice::ReadOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	QString qs;
	QStringList qsl;
	qs = qts.readLine();
	while (!qts.atEnd())
	{
		qs = qts.readLine();
		qsl = qs.split(",");
		user u(qsl);
		this->data.insert(u);
		this->keyring[u.username] = u.password;
	}
	qf.close();
}

void userManager::writeFile()
{
	QFile qf("data/user.txt");
	qf.open(QIODevice::WriteOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	qts << QString("用户ID,用户名,密码,联系方式,地址,钱包余额,用户状态");
	QString temp;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if ((*it).status == user::NORMAL)
		{
			temp = "正常";
		}
		else
		{
			temp = "封禁";
		}
		qts << '\n'
			<< (*it).ID << ',' << (*it).username << ',' << (*it).password << ',' << (*it).contact << ',' << (*it).address << ',' << QString::number((*it).balance, 10, 1) << ',' << temp;
	}
	qf.close();
}

bool userManager::userRegister(QString username, QString password, QString contact, QString address)
{
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if ((*it).username == username)
		{
			return false;
		}
	}
	user u(getNextID(), username, password, contact, address, 0, user::NORMAL);
	data.insert(u);
	keyring[u.username] = u.password;
	writeFile();
	return true;
}

bool userManager::checkPassword(QString username, QString password)
{
	readFile();
	return keyring[username] == password;
}

bool userManager::changeUserInfo(QString ID, int type, QString newValue)
{
	readFile();
	auto it = data.begin();
	for (; it != data.end(); it++)
	{
		if ((*it).ID == ID)
		{
			break;
		}
	}
	if (it == data.end())
	{
		return false;
	}
	user u = *it;
	switch (type)
	{
	case USERNAME:
		for (auto it2 = data.begin(); it2 != data.end(); it2++)
		{
			if ((*it2).username == newValue && it != it2)
			{
				return false;
			}
		}
		keyring.erase(u.username);
		u.username = newValue;
		keyring[u.username] = u.password;
		break;
	case PASSWORD:
		u.password = newValue;
		keyring[u.username] = newValue;
		break;
	case CONTACT:
		u.contact = newValue;
		break;
	case ADDRESS:
		u.address = newValue;
		break;
	case STATUS:
		if (newValue == "BANNED")
		{
			if (u.status == user::BANNED)
			{
				return false;
			}
			else
			{
				u.status = user::BANNED;
			}
		}
		break;
	case BALANCE:
		u.balance = newValue.toDouble();
		break;
	default:
		return false;
		break;
	}
	data.erase(it);
	data.insert(u);
	writeFile();
	return true;
}

bool userManager::banUser(QString ID)
{
	readFile();
	auto it = data.begin();
	for (; it != data.end(); it++)
	{
		if ((*it).ID == ID)
		{
			break;
		}
	}
	if (it == data.end())
	{
		return false;
	}
	else
	{
		if ((*it).status == user::BANNED)
		{
			return false;
		}
		else
		{
			user u = *it;
			data.erase(it);
			u.status = user::BANNED;
			data.insert(u);
			writeFile();
			return true;
		}
	}
}

bool userManager::compare(user u, QString qs, int type)
{
	switch (type)
	{
	case ID:
		return u.ID.contains(qs);
	case USERNAME:
		return u.username.contains(qs);
	case PASSWORD:
		return u.password.contains(qs);
	case CONTACT:
		return u.contact.contains(qs);
	case ADDRESS:
		return u.address.contains(qs);
	case BALANCE:
		return u.balance == qs.toDouble();
	case STATUS:
		return u.status == qs.toInt();
	default:
		return true;
	}
}

std::vector<user> userManager::search(QString qs, int type)
{
	readFile();
	std::vector<user> res;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if (compare(*it, qs, type))
		{
			res.push_back(*it);
		}
	}
	return res;
}

QString userManager::getNextID()
{
	QString ID = "U";
	int temp = data.size() + 1;
	if (temp < 10)
	{
		ID += "00";
	}
	else if (temp < 100)
	{
		ID += "0";
	}
	ID += QString::number(temp);
	return ID;
}

user userManager::getUser(QString username)
{
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if ((*it).username == username)
		{
			return *it;
		}
	}
	return user();
}

user userManager::getUserByID(QString ID)
{
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if ((*it).ID == ID)
		{
			return *it;
		}
	}
	return user();
}

bool userManager::getAndModify(int searchType, QString searchElement, int modityType, QString modifyElement)
{
	if (searchType == ID)
	{
		return changeUserInfo(searchElement, modityType, modifyElement);
	}
	else
	{
		for (auto it = data.begin(); it != data.end(); it++)
		{
			if (compare(*it, searchElement, searchType))
			{
				return changeUserInfo((*it).ID, modityType, modifyElement);
			}
		}
	}
	return false;
}
