#include "login.h"

login::login(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void login::onLoginButtonClicked()
{
	QString username = ui.usernameLineEdit->text();
}

void login::onRegisterButtonClicked()
{
}