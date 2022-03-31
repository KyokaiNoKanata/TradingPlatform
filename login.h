#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QDir>
#include "ui_login.h"
#include "adminWindow.h"
#include "registerWindow.h"
#include "userManager.h"
#include "calculatorWindow.h"
#include "userWindow.h"

class login : public QMainWindow
{
	Q_OBJECT

public:
	login(QWidget *parent = Q_NULLPTR);

public slots:
	void onLoginButtonClicked();
	void onRegisterButtonClicked();
	void onCalculatorButtonClicked();

private:
	Ui::loginClass ui;
	userManager um;
	QDir qd;
	bool adminLogin();
	bool userLogin();
};
