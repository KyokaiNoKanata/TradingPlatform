#include "instructionGenerator.h"

QString instructionGenerator::generate(int operationType, int dataType, QStringList qsl)
{
	res.clear();
	QString qs;
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
	case INSERT:
		res = "INSERT INTO " + qs + " VALUES (";
		for (auto it = qsl.begin(); it != qsl.end(); it++)
		{
			if (it != qsl.begin())
			{
				res.append(",");
			}
			res.append(*it);
		}
		res.append(")");
		break;
	case UPDATE:
		res = "UPDATE " + qs + " SET ";
		qs = "WHERE " + qsl[0] + " = " + qsl[1];
		res.append(qsl[2] + " = " + qsl[3]);
		res.append(" ");
		res.append(qs);
		break;
	case SELECT:
		res = "SELECT * FROM " + qs;
		if (!qsl.isEmpty())
		{
			res.append(" WHERE " + qsl[0] + " CONTAINS " + qsl[1]);
		}
		break;
	default:
		break;
	}
	writeFile();
	return res;
}

void instructionGenerator::writeFile()
{
	QFile qf("data/commands.txt");
	qf.open(QIODevice::ReadWrite | QIODevice::Append);
	QTextStream qts(&qf);
	qts << qdt.currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << ": " << res << '\n';
	qf.close();
}
