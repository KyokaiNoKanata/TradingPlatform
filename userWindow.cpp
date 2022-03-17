﻿#include "userWindow.h"

userWindow::userWindow(user u, QWidget* parent) :QMainWindow(parent)
{
	this->u = u;
	ui.setupUi(this);
}

userWindow::~userWindow()
{
}

void userWindow::onBuyerSearchPushButtonClicked()
{

}

void userWindow::onBuyerBuyPushButtonClicked()
{
}

void userWindow::onBuyerViewAllPushButtonClicked()
{
	i = ig.generate(instructionGenerator::SELECT, instructionGenerator::COMMODITY, QStringList());
	std::vector<commodity>temp_data = id.selectCommodity(i);
	std::vector<commodity>data;
	for (auto it = temp_data.begin(); it != temp_data.end(); it++)
	{
		if ((*it).status == commodity::NORMAL)
		{
			data.push_back(*it);
		}
	}
	ui.buyerCommodityTableWidget->setRowCount(data.size());
	for (int i = 0; i < data.size(); i++)
	{
		ui.buyerCommodityTableWidget->setItem(i, 0, new QTableWidgetItem(data[i].ID));
		ui.buyerCommodityTableWidget->setItem(i, 1, new QTableWidgetItem(data[i].name));
		ui.buyerCommodityTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(data[i].price, 10, 1)));
		ui.buyerCommodityTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(data[i].quantity, 10, 0)));
		ui.buyerCommodityTableWidget->setItem(i, 4, new QTableWidgetItem(data[i].information));
		ui.buyerCommodityTableWidget->setItem(i, 5, new QTableWidgetItem(data[i].sellerID));
		ui.buyerCommodityTableWidget->setItem(i, 6, new QTableWidgetItem(data[i].shelfTime));
		ui.buyerCommodityTableWidget->setItem(i, 7, new QTableWidgetItem(data[i].status ? "已下架" : "销售中"));
	}
	ui.buyerCommodityTableWidget->resizeColumnsToContents();
	ui.buyerCommodityTableWidget->resizeRowsToContents();
}

void userWindow::onShowOrderPushButtonClicked()
{
	i = ig.generate(instructionGenerator::SELECT, instructionGenerator::ORDER, QStringList());
	std::vector<order>temp_data = id.selectOrder(i);
	std::vector<order>data;
	for (auto it = temp_data.begin(); it != temp_data.end(); it++)
	{
		if ((*it).sellerID == u.ID || (*it).buyerID == u.ID)
		{
			data.push_back(*it);
		}
	}
	ui.orderTableWidget->setRowCount(data.size());
	for (int i = 0; i < data.size(); i++)
	{
		ui.orderTableWidget->setItem(i, 0, new QTableWidgetItem(data[i].ID));
		ui.orderTableWidget->setItem(i, 1, new QTableWidgetItem(data[i].commodityID));
		ui.orderTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(data[i].price, 10, 1)));
		ui.orderTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(data[i].quantity, 10, 0)));
		ui.orderTableWidget->setItem(i, 4, new QTableWidgetItem(data[i].tradeTime));
		ui.orderTableWidget->setItem(i, 5, new QTableWidgetItem(data[i].sellerID));
		ui.orderTableWidget->setItem(i, 6, new QTableWidgetItem(data[i].buyerID));
	}
	ui.orderTableWidget->resizeColumnsToContents();
	ui.orderTableWidget->resizeRowsToContents();
}

void userWindow::onSellerViewAllPushButtonClicked()
{
	i = ig.generate(instructionGenerator::SELECT, instructionGenerator::COMMODITY, QStringList());
	std::vector<commodity>temp_data = id.selectCommodity(i);
	std::vector<commodity>data;
	for (auto it = temp_data.begin(); it != temp_data.end(); it++)
	{
		if ((*it).sellerID == u.ID)
		{
			data.push_back(*it);
		}
	}
	ui.sellerCommodityTableWidget->setRowCount(data.size());
	for (int i = 0; i < data.size(); i++)
	{
		ui.sellerCommodityTableWidget->setItem(i, 0, new QTableWidgetItem(data[i].ID));
		ui.sellerCommodityTableWidget->setItem(i, 1, new QTableWidgetItem(data[i].name));
		ui.sellerCommodityTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(data[i].price, 10, 1)));
		ui.sellerCommodityTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(data[i].quantity, 10, 0)));
		ui.sellerCommodityTableWidget->setItem(i, 4, new QTableWidgetItem(data[i].information));
		ui.sellerCommodityTableWidget->setItem(i, 5, new QTableWidgetItem(data[i].sellerID));
		ui.sellerCommodityTableWidget->setItem(i, 6, new QTableWidgetItem(data[i].shelfTime));
		ui.sellerCommodityTableWidget->setItem(i, 7, new QTableWidgetItem(data[i].status ? "已下架" : "销售中"));
	}
	ui.sellerCommodityTableWidget->resizeColumnsToContents();
	ui.sellerCommodityTableWidget->resizeRowsToContents();
}

void userWindow::onSellerNewCommodityPushButtonClicked()
{
}

void userWindow::onSellerModifyPushButtonClicked()
{
}

void userWindow::onSellerBanPushButtonClicked()
{
}

void userWindow::onLogOutPushButtonClicked()
{
	auto l = new login();
	l->show();
	this->close();
}

void userWindow::onChangeUsernamePushButtonClicked()
{
}

void userWindow::onChangeContactPushButtonClicked()
{
}

void userWindow::onChangeAddressPushButtonClicked()
{
}
