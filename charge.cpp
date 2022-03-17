#include "charge.h"

charge::charge(QStringList qsl)
{
	userID = qsl[0];
	chargeAmount = qsl[1].toDouble();
	chargeTime = qsl[2];
}
