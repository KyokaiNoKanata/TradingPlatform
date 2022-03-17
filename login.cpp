#include "login.h"

login::login(QWidget* parent) :QMainWindow(parent)
{
	ui.setupUi(this);
}

void login::onLoginButtonClicked()
{
	if (ui.usernameLineEdit->text().isEmpty())
	{
		QMessageBox::information(nullptr, "Login Failed", "Please Enter Username");
	}
	else if (ui.passwordLineEdit->text().isEmpty())
	{
		QMessageBox::information(nullptr, "Login Failed", "Please Enter Password");
	}
	else
	{
		if (ui.adminModeRadioButton->isChecked())
		{
			if (adminLogin())
			{
				QMessageBox::information(nullptr, "info", "Login Success");
				auto aw = new adminWindow();
				aw->show();
				close();
			}
			else
			{
				QMessageBox::information(nullptr, "Login Failed", "Wrong Username or Password");
			}
		}
		else if (ui.userModeRadioButton->isChecked())
		{
			if (userLogin())
			{
				QMessageBox::information(nullptr, "info", "Login Success");
			}
			else
			{
				QMessageBox::information(nullptr, "Login Failed", "Wrong Username or Password");
			}
		}
		else
		{
			QMessageBox::information(nullptr, "Login Failed", "Please Select a Mode");
		}
	}
}

void login::onRegisterButtonClicked()
{
	auto rw = new registerWindow();
	rw->show();
}

void login::onCalculatorButtonClicked()
{
	auto cw = new calculatorWindow();
	cw->show();
}

bool login::adminLogin()
{
	return ui.usernameLineEdit->text() == "admin" && ui.passwordLineEdit->text() == "123456";
}

bool login::userLogin()
{
	return um.checkPassword(ui.usernameLineEdit->text(), ui.passwordLineEdit->text());
}
