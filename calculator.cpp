#include "calculator.h"

calculator::calculator()
{
	init();
}

calculator::~calculator()
{
}

QString calculator::calculate(QString expression)
{
	init();
	if (expression.count('(') != expression.count(')'))
	{
		return "ERROR: Bracket does not Match!";
	}
	QString qs;
	double d;
	for (auto it = expression.begin(); it != expression.end(); it++)
	{

		if ((*it).isSymbol())
		{
			if ((symbolStack.top() == '(' || symbolStack.isEmpty()) && *it == '-')
			{
				pushSybmol('_');
			}
			else
			{
				if (prevType == SYMBOL)
				{
					return "ERROR: Symbol Used Incorrectly!";
				}
				if (!pushSybmol(*it))
				{
					return "ERROR: Math Error!";
				}
			}
			prevType = SYMBOL;
		}
		else if ((*it).isDigit())
		{
			if (prevType == NUMBER)
			{
				return "ERROR: Symbol Used Incorrectly!";
			}
			qs.clear();
			while (it != expression.end() && ((*it).isDigit() || *it == '.'))
			{
				qs += *it;
				it++;
			}
			d = qs.toDouble();
			if (symbolStack.top() == '_')
			{
				symbolStack.pop();
				d = -d;
			}
			dataStack.push(d);
			prevType = NUMBER;
			if (it == expression.end())
			{
				break;
			}
		}
		else if ((*it).isSpace())
		{
			continue;
		}
	}
	if (!tidy())
	{
		return "ERROR: Math Error!";
	}
	if (!symbolStack.isEmpty())
	{
		return "ERROR: Symbol Used Incorrectly!";
	}
	return QString::number(dataStack.top(), 10, 1);
}

void calculator::init()
{
	prevType = EMPTY;
	symbolStack.clear();
	dataStack.clear();
}

int calculator::priority(QChar qc)
{
	if (qc == '(')
	{
		return 3;
	}
	else if (qc == '_')
	{
		return 2;
	}
	else if (qc == '*' || qc == '/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

double calculator::singleCalculate(double d1, double d2, QChar qc)
{
	if (qc == '+')
	{
		return d1 + d2;
	}
	else if (qc == '-')
	{
		return d1 - d2;
	}
	else if (qc == '*')
	{
		return d1 * d2;
	}
	else if (qc == '/')
	{
		return d1 / d2;
	}
	else
	{
		return 0.0;
	}
}

bool calculator::pushSybmol(QChar qc)
{
	if (qc == ')')
	{
		return tidy();
	}
	else if (symbolStack.top() != '(' && priority(symbolStack.top()) >= priority(qc))
	{
		return tidy();
	}
	else
	{
		symbolStack.push(qc);
		return true;
	}
}

bool calculator::tidy()
{
	QChar qc = symbolStack.pop();
	while (!symbolStack.isEmpty() && qc != '(')
	{
		double d2 = dataStack.pop();
		double d1 = dataStack.pop();
		if (qc == '/' && d2 == 0)
		{
			return false;
		}
		else
		{
			dataStack.push(singleCalculate(d1, d2, qc));
		}
		qc = symbolStack.pop();
	}
	return true;
}
