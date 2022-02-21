#include "login.h"

login::login(QWidget* parent)
	: QMainWindow(parent)
{
	this->um.readFile();
	this->ui.setupUi(this);
}

void login::onLoginButtonClicked()
{
	if (this->ui.adminModeRadioButton->isChecked())
	{
		if (this->adminLogin())
		{
			QMessageBox::information(nullptr, "info", "Login Success");
			auto* aw = new adminWindow();
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

void login::onRegisterButtonClicked()
{
}

bool login::adminLogin()
{
	return this->ui.usernameLineEdit->text() == "admin" && this->ui.passwordLineEdit->text() == "123456";
}

bool login::userLogin()
{
	return this->um.checkPassword(this->ui.usernameLineEdit->text(), this->ui.passwordLineEdit->text());
}
