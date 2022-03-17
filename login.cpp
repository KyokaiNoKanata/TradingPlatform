#include "login.h"

login::login(QWidget* parent) :QMainWindow(parent)
{
	ui.setupUi(this);
}

void login::onLoginButtonClicked()
{
	if (ui.usernameLineEdit->text().isEmpty())
	{
		QMessageBox::information(nullptr, "登录失败", "请输入用户名");
	}
	else if (ui.passwordLineEdit->text().isEmpty())
	{
		QMessageBox::information(nullptr, "登录失败", "请输入密码");
	}
	else
	{
		if (ui.adminModeRadioButton->isChecked())
		{
			if (adminLogin())
			{
				QMessageBox::information(nullptr, "提示", "登录成功");
				auto aw = new adminWindow();
				aw->show();
				this->close();
			}
			else
			{
				QMessageBox::information(nullptr, "登录失败", "用户名或密码错误");
			}
		}
		else if (ui.userModeRadioButton->isChecked())
		{
			if (userLogin())
			{
				user u = um.getUser(ui.usernameLineEdit->text());
				if (u.status == user::NORMAL)
				{
					QMessageBox::information(nullptr, "提示", "登录成功");
					auto uw = new userWindow(u);
					uw->show();
					this->close();
				}
				else
				{
					QMessageBox::information(nullptr, "登录失败", "您已被封禁");
				}
			}
			else
			{
				QMessageBox::information(nullptr, "提示", "用户名或密码错误");
			}
		}
		else
		{
			QMessageBox::information(nullptr, "登录失败", "请选择模式");
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
