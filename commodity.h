#pragma once

#include<QString>

class commodity
{
public:
	commodity(QString ID, QString name, QString price, QString quantity, QString information, QString sellerID, QString shelfTime, int status);
	QString ID;
	QString name;
	QString price;
	QString quantity;
	QString information;
	QString sellerID;
	QString shelfTime;
	int status;
	bool operator<(commodity b);
};

