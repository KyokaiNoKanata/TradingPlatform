#pragma once

#include <QMainWindow>
#include "ui_userWindow.h"
#include "login.h"
#include "instructionGenerator.h"
#include "instructionDecoder.h"

class userWindow : public QMainWindow
{
	Q_OBJECT

public:
	userWindow(user u, QWidget* parent = Q_NULLPTR);
	~userWindow();

public slots:
	void onBuyerSearchPushButtonClicked();
	void onBuyerBuyPushButtonClicked();
	void onBuyerViewAllPushButtonClicked();
	void onShowOrderPushButtonClicked();
	void onSellerViewAllPushButtonClicked();
	void onSellerNewCommodityPushButtonClicked();
	void onSellerModifyPushButtonClicked();
	void onSellerBanPushButtonClicked();
	void onLogOutPushButtonClicked();
	void onChangeUsernamePushButtonClicked();
	void onChangeContactPushButtonClicked();
	void onChangeAddressPushButtonClicked();
	void onBuyerShowOrderPushButtonClicked();
	void onSellerShowOrderPushButtonClicked();

private:
	Ui::userWindow ui;
	user u;
	QString i;
	instructionGenerator ig;
	instructionDecoder id;
};
