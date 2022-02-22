#pragma once

#include <QString>
#include <QStringList>

class commodity
{
public:
	commodity(QStringList qsl);
	commodity(QString ID, QString name, QString price, int quantity, QString information, QString sellerID, QString shelfTime, int status);
	QString ID;
	QString name;
	QString price;
	int quantity;
	QString information;
	QString sellerID;
	QString shelfTime;
	int status;
	bool operator<(commodity b)const;
};

