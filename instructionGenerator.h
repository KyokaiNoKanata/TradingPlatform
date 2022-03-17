#pragma once

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class instructionGenerator
{
public:
	enum operationTypeFlags { INSERT, SELECT, UPDATE };
	enum dataTypeFlags { COMMODITY, ORDER, USER };
	QString generate(int operationType, int dataType, QStringList qsl);

private:
	QString res;
	QDateTime qdt;
	void writeFile();
};
