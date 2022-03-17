#pragma once

#include <QString>
#include <QStringList>

class instructionGenerator
{
public:
	enum operationTypeFlags { INSERT, UPDATE, SELECT };
	enum dataTypeFlags { COMMODITY, ORDER, USER };
	QString generate(int operationType, int dataType, QStringList qsl);
};

