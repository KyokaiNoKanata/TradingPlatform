#pragma once

#include <QWidget>
#include "ui_registerWindow.h"

class registerWindow : public QWidget
{
	Q_OBJECT

public:
	registerWindow(QWidget *parent = Q_NULLPTR);
	~registerWindow();

private:
	Ui::registerWindow ui;
};
