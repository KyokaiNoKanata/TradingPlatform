#include "registerWindow.h"

registerWindow::registerWindow(QWidget* parent) :QWidget(parent)
{
	ui.setupUi(this);
}

registerWindow::~registerWindow()
{
}

void registerWindow::onRegisterButtonClicked()
{
	QString username = ui.usernameLineEdit->text(),
		password = ui.passwordLineEdit->text(),
		password_2 = ui.passwordLineEdit_2->text(),
		contact = ui.contactLineEdit->text(),
		address = ui.addressLineEdit->text();
	if (username.isEmpty())
	{
		QMessageBox::information(nullptr, "Register Failed", "Please Enter Username");
	}
	else if (username.length() > 10)
	{
		QMessageBox::information(nullptr, "Register Failed", "Username Too Long");
	}
	else if (password.isEmpty())
	{
		QMessageBox::information(nullptr, "Register Failed", "Please Enter Password");
	}
	else if (password.length() > 20)
	{
		QMessageBox::information(nullptr, "Register Failed", "Password Too Long");
	}
	else if (password_2.isEmpty())
	{
		QMessageBox::information(nullptr, "Register Failed", "Please Repeat Password");
	}
	else if (password != password_2)
	{
		QMessageBox::information(nullptr, "Register Failed", "Password Does Not Match");
	}
	else if (contact.isEmpty())
	{
		QMessageBox::information(nullptr, "Register Failed", "Please Enter Contact");
	}
	else if (contact.length() > 20)
	{
		QMessageBox::information(nullptr, "Register Failed", "Contact Too Long");
	}
	else if (address.isEmpty())
	{
		QMessageBox::information(nullptr, "Register Failed", "Please Enter Address");
	}
	else if (address.length() > 20)
	{
		QMessageBox::information(nullptr, "Register Failed", "Address Too Long");
	}
	else
	{
		if (um.userRegister(username, password, contact, address))
		{
			QMessageBox::information(nullptr, "info", "Register Success");
		}
		else
		{
			QMessageBox::information(nullptr, "Register Failed", "Username Already Exists");
		}
	}
}