#pragma once

#include <QWidget>
#include <QMessageBox>
#include "userManager.h"
#include "instructionGenerator.h"
#include "instructionDecoder.h"
#include "ui_registerWindow.h"

class registerWindow : public QWidget
{
	Q_OBJECT

public:
	registerWindow(QWidget *parent = Q_NULLPTR);
	~registerWindow();

public slots:
	void onRegisterButtonClicked();

private:
	Ui::registerWindow ui;
	QString i;
	instructionGenerator ig;
	instructionDecoder id;
};
