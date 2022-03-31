#pragma once

#include <QString>
#include <QStringList>

class commodity
{
public:
	commodity(QStringList qsl);
	commodity(QString ID, QString name, double price, int quantity, QString information, QString sellerID, QString shelfTime, int status);
	enum statusFlags
	{
		NORMAL,
		BANNED
	};
	QString ID;
	QString name;
	double price;
	int quantity;
	QString information;
	QString sellerID;
	QString shelfTime;
	bool status;
	bool operator<(commodity b) const;
};
