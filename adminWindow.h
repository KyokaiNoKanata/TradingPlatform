#pragma once

#include <QMainWindow>
#include "ui_adminWindow.h"
#include "userManager.h"
#include "commodityManager.h"

class adminWindow :public QMainWindow
{
	Q_OBJECT

public:
	adminWindow(QWidget* parent = Q_NULLPTR);
	~adminWindow();

public slots:
	void onCommoditySearchPushButtonClicked();
	void onCommodityBanPushButtonClicked();
	void onCommodityViewAllPushButtonClicked();
	void onUserSearchPushButtonClicked();
	void onUserBanPushButtonClicked();
	void onUserViewAllPushButtonClicked();

private:
	Ui::adminWindow ui;
	userManager um;
	commodityManager cm;
};
