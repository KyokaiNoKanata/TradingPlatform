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
	QString typeMap[] = { "ID" ,"name","price","quantity","information","sellerID","shelfTime","status" };
	QStringList qsl;
	qsl.append(typeMap[ui.commodityTableWidget->currentColumn()]);
	qsl.append(ui.commoditySearchLineEdit->text());
	i = ig.generate(instructionGenerator::SELECT, instructionGenerator::COMMODITY, qsl);
	std::vector<commodity>data = id.selectCommodity(i);
	ui.commodityTableWidget->setRowCount(data.size());
	for (int i = 0; i < data.size(); i++)
	{
		ui.commodityTableWidget->setItem(i, 0, new QTableWidgetItem(data[i].ID));
		ui.commodityTableWidget->setItem(i, 1, new QTableWidgetItem(data[i].name));
		ui.commodityTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(data[i].price, 10, 1)));
		ui.commodityTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(data[i].quantity, 10, 0)));
		ui.commodityTableWidget->setItem(i, 4, new QTableWidgetItem(data[i].information));
		ui.commodityTableWidget->setItem(i, 5, new QTableWidgetItem(data[i].sellerID));
		ui.commodityTableWidget->setItem(i, 6, new QTableWidgetItem(data[i].shelfTime));
		ui.commodityTableWidget->setItem(i, 7, new QTableWidgetItem(data[i].status != commodity::NORMAL ? "已下架" : "销售中"));
	}
	ui.commodityTableWidget->resizeColumnsToContents();
	ui.commodityTableWidget->resizeRowsToContents();
}

void adminWindow::onCommodityBanPushButtonClicked()
{
	int row = ui.commodityTableWidget->currentRow();
	QString ID = ui.commodityTableWidget->item(row, 0)->text();
	QStringList qsl;
	qsl.append("ID");
	qsl.append(ID);
	qsl.append("status");
	qsl.append("BANNED");
	i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::COMMODITY, qsl);
	if (id.modifyOperation(i))
	{
		QMessageBox::information(nullptr, "提示", "下架成功");
	}
	else
	{
		QMessageBox::information(nullptr, "错误", "下架失败");
	}
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
		ui.commodityTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(data[i].quantity, 10, 0)));
		ui.commodityTableWidget->setItem(i, 4, new QTableWidgetItem(data[i].information));
		ui.commodityTableWidget->setItem(i, 5, new QTableWidgetItem(data[i].sellerID));
		ui.commodityTableWidget->setItem(i, 6, new QTableWidgetItem(data[i].shelfTime));
		ui.commodityTableWidget->setItem(i, 7, new QTableWidgetItem(data[i].status != commodity::NORMAL ? "已下架" : "销售中"));
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
	QString ID = ui.userTableWidget->item(row, 0)->text();
	QStringList qsl;
	qsl.append("ID");
	qsl.append(ID);
	qsl.append("status");
	qsl.append("BANNED");
	i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::USER, qsl);
	if (id.modifyOperation(i))
	{
		QMessageBox::information(nullptr, "提示", "封禁成功");
	}
	else
	{
		QMessageBox::information(nullptr, "错误", "封禁失败");
	}
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
		ui.userTableWidget->setItem(i, 6, new QTableWidgetItem(data[i].status ? "封禁" : "正常"));
	}
	ui.userTableWidget->resizeColumnsToContents();
	ui.userTableWidget->resizeRowsToContents();
}

void adminWindow::onOrderViewAllPushButtonClicked()
{
	i = ig.generate(instructionGenerator::SELECT, instructionGenerator::ORDER, QStringList());
	std::vector<order>data = id.selectOrder(i);
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
