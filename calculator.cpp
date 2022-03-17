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
		return "ERROR 0: 括号不匹配";
	}
	QString qs;
	double d;
	int leftCount = 0;
	int rightCount = 0;
	for (auto it = expression.begin(); it != expression.end(); it++)
	{
		if (symbolCheck(*it))
		{
			if (*it == '(')
			{
				leftCount++;
			}
			if ((symbolStack.isEmpty() && dataStack.isEmpty() || !symbolStack.isEmpty() && symbolStack.top() == '(' && prevType == SYMBOL) && *it == '-')
			{
				pushSymbol('_');
			}
			else
			{
				if (prevType == SYMBOL && *it != '(')
				{
					return "ERROR 1: 符号误用";
				}
				else if (!pushSymbol(*it))
				{
					return "ERROR 4: 数学错误";
				}
			}
			if (*it == ')')
			{
				rightCount++;
				if (rightCount > leftCount)
				{
					return "ERROR 0: 括号不匹配";
				}
				prevType = NUMBER;
			}
			else
			{
				prevType = SYMBOL;
			}
		}
		else if ((*it).isNumber())
		{
			if (prevType == NUMBER)
			{
				return "ERROR 2: 符号误用";
			}
			qs.clear();
			while (it != expression.end() && ((*it).isNumber() || *it == '.'))
			{
				qs.append(*it);
				it++;
			}
			d = qs.toDouble();
			if (!symbolStack.isEmpty() && symbolStack.top() == '_')
			{
				symbolStack.pop();
				d = -d;
			}
			dataStack.push(d);
			prevType = NUMBER;
			it--;
		}
		else if ((*it).isSpace())
		{
			continue;
		}
		else
		{
			return "ERROR 5: 非法输入";
		}
	}
	if (!tidy())
	{
		return "ERROR 4: 数学错误";
	}
	if (!symbolStack.isEmpty())
	{
		return "ERROR 3: 符号误用";
	}
	return QString::number(dataStack.top(), 10, 1);
}

void calculator::init()
{
	prevType = SYMBOL;
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

bool calculator::symbolCheck(QChar qc)
{
	return qc == '+' || qc == '-' || qc == '*' || qc == '/' || qc == '(' || qc == ')';
}

bool calculator::pushSymbol(QChar qc)
{
	if (qc == ')')
	{
		bool temp = tidy();
		symbolStack.pop();
		return temp;
	}
	else if (!symbolStack.isEmpty() && symbolStack.top() != '(' && priority(symbolStack.top()) >= priority(qc))
	{
		bool temp = tidy();
		symbolStack.push(qc);
		return temp;
	}
	else
	{
		symbolStack.push(qc);
		return true;
	}
}

bool calculator::tidy()
{
	if (symbolStack.isEmpty())
	{
		return true;
	}
	else
	{
		QChar qc;
		while (!symbolStack.isEmpty())
		{
			qc = symbolStack.pop();
			if (qc == '(')
			{
				symbolStack.push(qc);
				return true;
			}
			else
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
			}
		}
		return true;
	}
}
