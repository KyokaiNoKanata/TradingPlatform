#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_login.h"
#include "userManager.h"

class login :public QMainWindow
{
	Q_OBJECT

public:
	login(QWidget* parent = Q_NULLPTR);

public slots:
	void onLoginButtonClicked();
	void onRegisterButtonClicked();

private:
	Ui::loginClass ui;
	userManager um;
};
