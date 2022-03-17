#pragma once

#include <QMainWindow>
#include "ui_userWindow.h"

class userWindow : public QMainWindow
{
	Q_OBJECT

public:
	userWindow(QWidget *parent = Q_NULLPTR);
	~userWindow();

private:
	Ui::userWindow ui;
};
