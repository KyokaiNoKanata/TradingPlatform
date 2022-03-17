#pragma once

#include <QString>
#include <QStringList>

class charge
{
public:
	charge(QStringList qsl);
	QString userID;
	double chargeAmount;
	QString chargeTime;
};

