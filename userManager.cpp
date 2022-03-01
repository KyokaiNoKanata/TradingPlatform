#include "userManager.h"

userManager::userManager()
{
	readFile();
}

userManager::~userManager()
{
	data.clear();
	keyring.clear();
}

void userManager::readFile()
{
	QFile qf("data/user.txt");
	qf.open(QIODeviceBase::ReadOnly);
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
	qts << "用户ID,用户名,密码,联系方式,地址,钱包余额,用户状态";
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
		qts << '\n' << (*it).ID << ',' << (*it).username << ',' << (*it).password << ',' << (*it).contact << ',' << (*it).address << ',' << (*it).balance << ',' << temp;
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
	QString ID = "U";
	auto temp = data.size() + 1;
	if (temp < 10)
	{
		ID += "00";
	}
	else if (temp < 100)
	{
		ID += "0";
	}
	ID += QString::number(temp);
	user u(ID, username, password, contact, address, 0, user::NORMAL);
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
	data.erase(it);
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
	default:
		return false;
		break;
	}
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
		user u = *it;
		data.erase(it);
		if (u.status == user::BANNED)
		{
			return false;
		}
		else
		{
			u.status = user::BANNED;
			data.insert(u);
			writeFile();
			return true;
		}
	}
}

std::vector<user> userManager::instrctionDecode(QString qs)
{
	return std::vector<user>();
}
