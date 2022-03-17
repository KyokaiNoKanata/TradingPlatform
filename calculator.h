#pragma once

#include <QString>
#include <QStack>
#include <QChar>

class calculator
{
public:
	calculator();
	~calculator();
	QString calculate(QString expression);

private:
	QStack<QChar>symbolStack;
	QStack<double>dataStack;
	enum typeFlag { SYMBOL, NUMBER };
	bool prevType;
	void init();
	int priority(QChar qc);
	double singleCalculate(double d1, double d2, QChar qc);
	bool symbolCheck(QChar qc);
	bool pushSybmol(QChar qc);
	bool tidy();
};
