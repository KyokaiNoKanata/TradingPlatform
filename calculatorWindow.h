#pragma once

#include <QWidget>
#include "ui_calculatorWindow.h"
#include "calculator.h"

class calculatorWindow :public QWidget
{
	Q_OBJECT

public:
	calculatorWindow(QWidget* parent = Q_NULLPTR);
	~calculatorWindow();

public slots:
	void onCalculateButtonClicked();

private:
	Ui::calculatorWindow ui;
	calculator c;
};
