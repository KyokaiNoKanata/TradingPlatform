#pragma once

#include <QMainWindow>
#include "ui_adminWindow.h"
#include "userManager.h"

class adminWindow :public QMainWindow
{
	Q_OBJECT

public:
	adminWindow(QWidget* parent = Q_NULLPTR);
	~adminWindow();

private:
	Ui::adminWindow ui;
	userManager um;
};
