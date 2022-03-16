#include "adminWindow.h"

adminWindow::adminWindow(QWidget* parent) :QMainWindow(parent)
{
	ui.setupUi(this);
}

adminWindow::~adminWindow()
{
}

void adminWindow::onCommoditySearchPushButtonClicked()
{
}

void adminWindow::onCommodityBanPushButtonClicked()
{
}

void adminWindow::onCommodityViewAllPushButtonClicked()
{
	i = ig.generate(instructionGenerator::SELECT, instructionGenerator::COMMODITY, QStringList());
	std::vector<commodity>data = id.selectCommodity(i);
	ui.commodityTableWidget->setRowCount(data.size());
	for (int i = 0; i < data.size(); i++)
	{
		ui.commodityTableWidget->setItem(i, 0, new QTableWidgetItem(data[i].ID));
		ui.commodityTableWidget->setItem(i, 1, new QTableWidgetItem(data[i].name));
		ui.commodityTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(data[i].price, 10, 1)));
		ui.commodityTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(data[i].price, 10, 0)));
		ui.commodityTableWidget->setItem(i, 4, new QTableWidgetItem(data[i].information));
		ui.commodityTableWidget->setItem(i, 5, new QTableWidgetItem(data[i].sellerID));
		ui.commodityTableWidget->setItem(i, 6, new QTableWidgetItem(data[i].shelfTime));
		ui.commodityTableWidget->setItem(i, 7, new QTableWidgetItem(data[i].status ? "已下架" : "销售中"));
	}
	ui.commodityTableWidget->resizeColumnsToContents();
	ui.commodityTableWidget->resizeRowsToContents();
}

void adminWindow::onUserSearchPushButtonClicked()
{
}

void adminWindow::onUserBanPushButtonClicked()
{
	int row = ui.userTableWidget->currentRow();
	int column = ui.userTableWidget->currentColumn();
	QString ID = ui.userTableWidget->item(row, 0)->text();
	ui.userSearchLineEdit->setText(ID);
}

void adminWindow::onUserViewAllPushButtonClicked()
{
	i = ig.generate(instructionGenerator::SELECT, instructionGenerator::USER, QStringList());
	std::vector<user>data = id.selectUser(i);
	ui.userTableWidget->setRowCount(data.size());
	for (int i = 0; i < data.size(); i++)
	{
		ui.userTableWidget->setItem(i, 0, new QTableWidgetItem(data[i].ID));
		ui.userTableWidget->setItem(i, 1, new QTableWidgetItem(data[i].username));
		ui.userTableWidget->setItem(i, 2, new QTableWidgetItem(data[i].password));
		ui.userTableWidget->setItem(i, 3, new QTableWidgetItem(data[i].contact));
		ui.userTableWidget->setItem(i, 4, new QTableWidgetItem(data[i].address));
		ui.userTableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(data[i].balance, 10, 1)));
		ui.userTableWidget->setItem(i, 6, new QTableWidgetItem(data[i].status ? "已封禁" : "正常"));
	}
	ui.userTableWidget->resizeColumnsToContents();
	ui.userTableWidget->resizeRowsToContents();
}
