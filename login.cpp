#include "login.h"

login::login(QWidget* parent) :QMainWindow(parent)
{
	this->ui.setupUi(this);
}

void login::onLoginButtonClicked()
{
	if (this->ui.usernameLineEdit->text().isEmpty())
	{
		QMessageBox::information(nullptr, "Login Failed", "Please Enter Username");
	}
	else if (this->ui.passwordLineEdit->text().isEmpty())
	{
		QMessageBox::information(nullptr, "Login Failed", "Please Enter Password");
	}
	else
	{
		if (this->ui.adminModeRadioButton->isChecked())
		{
			if (this->adminLogin())
			{
				QMessageBox::information(nullptr, "info", "Login Success");
				auto aw = new adminWindow();
				aw->show();
				this->close();
			}
			else
			{
				QMessageBox::information(nullptr, "Login Failed", "Wrong Username or Password");
			}
		}
		else if (this->ui.userModeRadioButton->isChecked())
		{
			if (this->userLogin())
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
	return this->ui.usernameLineEdit->text() == "admin" && this->ui.passwordLineEdit->text() == "123456";
}

bool login::userLogin()
{
	um.readFile();
	return this->um.checkPassword(this->ui.usernameLineEdit->text(), this->ui.passwordLineEdit->text());
}
