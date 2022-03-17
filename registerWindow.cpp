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
		QMessageBox::information(nullptr, "注册失败", "请输入用户名");
	}
	else if (username.length() > 10)
	{
		QMessageBox::information(nullptr, "注册失败", "用户名过长");
	}
	else if (password.isEmpty())
	{
		QMessageBox::information(nullptr, "注册失败", "请输入密码");
	}
	else if (password.length() > 20)
	{
		QMessageBox::information(nullptr, "注册失败", "密码过长");
	}
	else if (password_2.isEmpty())
	{
		QMessageBox::information(nullptr, "注册失败", "请重复密码");
	}
	else if (password != password_2)
	{
		QMessageBox::information(nullptr, "注册失败", "两次密码不一致");
	}
	else if (contact.isEmpty())
	{
		QMessageBox::information(nullptr, "注册失败", "请输入联系方式");
	}
	else if (contact.length() > 20)
	{
		QMessageBox::information(nullptr, "注册失败", "联系方式过长");
	}
	else if (address.isEmpty())
	{
		QMessageBox::information(nullptr, "注册失败", "请输入地址");
	}
	else if (address.length() > 20)
	{
		QMessageBox::information(nullptr, "注册失败", "地址过长");
	}
	else
	{
		if (um.userRegister(username, password, contact, address))
		{
			QMessageBox::information(nullptr, "提示", "注册成功");
		}
		else
		{
			QMessageBox::information(nullptr, "注册失败", "用户名已存在");
		}
	}
}
