#include "instructionGenerator.h"

QString instructionGenerator::generate(int operationType, int dataType, QStringList qsl)
{
	QString qs;
	QString res;
	switch (dataType)
	{
	case COMMODITY:
		qs = "commodity";
		break;
	case ORDER:
		qs = "order";
		break;
	case USER:
		qs = "user";
		break;
	default:
		break;
	}
	switch (operationType)
	{
	case SELECT:
		res = "SELECT * FROM " + qs;
		if (!qsl.isEmpty())
		{
			res.append("WHERE " + qsl[0] + " CONTAINS " + qsl[1]);
		}
		return res;
	default:
		return QString();
	}
}
