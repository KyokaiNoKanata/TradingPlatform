#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include "ui_adminWindow.h"
#include "instructionGenerator.h"
#include "instructionDecoder.h"

class adminWindow : public QMainWindow
{
	Q_OBJECT

public:
	adminWindow(QWidget *parent = Q_NULLPTR);
	~adminWindow();

public slots:
	void onCommoditySearchPushButtonClicked();
	void onCommodityBanPushButtonClicked();
	void onCommodityViewAllPushButtonClicked();
	void onUserSearchPushButtonClicked();
	void onUserBanPushButtonClicked();
	void onUserViewAllPushButtonClicked();
	void onOrderViewAllPushButtonClicked();

private:
	Ui::adminWindow ui;
	QString i;
	instructionGenerator ig;
	instructionDecoder id;
};
