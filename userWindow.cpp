#include "userWindow.h"

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
	QString typeMap[] = { "ID","name","price","quantity","information","sellerID","shelfTime","status" };
	QStringList qsl;
	qsl.append(typeMap[ui.buyerCommodityTableWidget->currentColumn()]);
	qsl.append(ui.buyerSearchLineEdit->text());
	i = ig.generate(instructionGenerator::SELECT, instructionGenerator::COMMODITY, qsl);
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
		ui.buyerCommodityTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(data[i].quantity, 10)));
		ui.buyerCommodityTableWidget->setItem(i, 4, new QTableWidgetItem(data[i].information));
		ui.buyerCommodityTableWidget->setItem(i, 5, new QTableWidgetItem(data[i].sellerID));
		ui.buyerCommodityTableWidget->setItem(i, 6, new QTableWidgetItem(data[i].shelfTime));
		ui.buyerCommodityTableWidget->setItem(i, 7, new QTableWidgetItem(data[i].status != commodity::NORMAL ? "已下架" : "销售中"));
	}
	ui.buyerCommodityTableWidget->resizeColumnsToContents();
	ui.buyerCommodityTableWidget->resizeRowsToContents();
}

void userWindow::onBuyerBuyPushButtonClicked()
{
	if (ui.quantityLineEdit->text().isEmpty())
	{
		QMessageBox::information(nullptr, "购买失败", "请填写购买数量");
	}
	int buyQuantity = ui.quantityLineEdit->text().toInt();
	int price = ui.buyerCommodityTableWidget->item(ui.buyerCommodityTableWidget->currentRow(), 2)->text().toDouble();
	int quantity = ui.buyerCommodityTableWidget->item(ui.buyerCommodityTableWidget->currentRow(), 3)->text().toInt();
	QString commodityID = ui.buyerCommodityTableWidget->item(ui.buyerCommodityTableWidget->currentRow(), 0)->text();
	QString sellerID = ui.buyerCommodityTableWidget->item(ui.buyerCommodityTableWidget->currentRow(), 5)->text();
	if (buyQuantity > quantity)
	{
		QMessageBox::information(nullptr, "购买失败", "欲购买的数量超出商品数量");
	}
	else
	{
		if (buyQuantity * price > u.balance)
		{
			QMessageBox::information(nullptr, "购买失败", "余额不足");
		}
		else
		{
			QStringList qsl = { "ID",commodityID,"quantity",QString::number(quantity - buyQuantity,10,0) };
			i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::COMMODITY, qsl);
			id.modifyOperation(i);
			if (quantity == buyQuantity)
			{
				qsl.clear();
				qsl = { "ID",commodityID,"status","BANNED" };
				i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::COMMODITY, qsl);
				id.modifyOperation(i);
			}
			u.balance -= buyQuantity * price;
			qsl.clear();
			qsl = { "ID",u.ID,"balance",QString::number(u.balance,10,1) };
			i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::USER, qsl);
			userManager um;
			user seller = um.getUserByID(sellerID);
			seller.balance += buyQuantity + price;
			qsl.clear();
			qsl = { "ID",u.ID,"balance",QString::number(seller.balance,10,1) };
			i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::USER, qsl);
			id.modifyOperation(i);
			orderManager om;
			qsl.clear();
			qsl = { om.getNextID(),commodityID,QString::number(price,10,1),QString::number(buyQuantity),qdt.currentDateTime().toString("yyyy-MM-dd"),sellerID,u.ID };
			i = ig.generate(instructionGenerator::INSERT, instructionGenerator::ORDER, qsl);
			id.modifyOperation(i);
			QMessageBox::information(nullptr, "提示", "购买成功");
		}
	}
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
	auto ncm = new newCommodityWidget(u.ID);
	ncm->show();
}

void userWindow::onSellerModifyPushButtonClicked()
{
	int row = ui.sellerCommodityTableWidget->currentRow();
	QString ID = ui.sellerCommodityTableWidget->item(row, 0)->text();
	auto cmw = new commodityModifyWidget(ID);
	cmw->show();
}

void userWindow::onSellerBanPushButtonClicked()
{
	int row = ui.sellerCommodityTableWidget->currentRow();
	QString ID = ui.sellerCommodityTableWidget->item(row, 0)->text();
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

void userWindow::onLogOutPushButtonClicked()
{
	auto l = new login();
	l->show();
	this->close();
}

void userWindow::onChangeUsernamePushButtonClicked()
{
	QStringList qsl;
	qsl.append("ID");
	qsl.append(u.ID);
	qsl.append("username");
	qsl.append(ui.newValueLineEdit->text());
	i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::USER, qsl);
	if (id.modifyOperation(i))
	{
		QMessageBox::information(nullptr, "提示", "修改成功");
		u.contact = ui.newValueLineEdit->text();
	}
	else
	{
		QMessageBox::information(nullptr, "错误", "修改失败，存在同名用户");
	}
}

void userWindow::onChangeContactPushButtonClicked()
{
	QStringList qsl;
	qsl.append("ID");
	qsl.append(u.ID);
	qsl.append("contact");
	qsl.append(ui.newValueLineEdit->text());
	i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::USER, qsl);
	if (id.modifyOperation(i))
	{
		QMessageBox::information(nullptr, "提示", "修改成功");
		u.contact = ui.newValueLineEdit->text();
	}
	else
	{
		QMessageBox::information(nullptr, "错误", "修改失败");
	}
}

void userWindow::onChangeAddressPushButtonClicked()
{
	QStringList qsl;
	qsl.append("ID");
	qsl.append(u.ID);
	qsl.append("address");
	qsl.append(ui.newValueLineEdit->text());
	i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::USER, qsl);
	if (id.modifyOperation(i))
	{
		QMessageBox::information(nullptr, "提示", "修改成功");
		u.contact = ui.newValueLineEdit->text();
	}
	else
	{
		QMessageBox::information(nullptr, "错误", "修改失败");
	}
}

void userWindow::onBuyerShowOrderPushButtonClicked()
{
	i = ig.generate(instructionGenerator::SELECT, instructionGenerator::ORDER, QStringList());
	std::vector<order>temp_data = id.selectOrder(i);
	std::vector<order>data;
	for (auto it = temp_data.begin(); it != temp_data.end(); it++)
	{
		if ((*it).buyerID == u.ID)
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

void userWindow::onSellerShowOrderPushButtonClicked()
{
	i = ig.generate(instructionGenerator::SELECT, instructionGenerator::ORDER, QStringList());
	std::vector<order>temp_data = id.selectOrder(i);
	std::vector<order>data;
	for (auto it = temp_data.begin(); it != temp_data.end(); it++)
	{
		if ((*it).sellerID == u.ID)
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

void userWindow::onShowInfoPushButtonClicked()
{
	ui.showIDLineEdit->setText(u.ID);
	ui.showUsernameLineEdit->setText(u.username);
	ui.showContactLineEdit->setText(u.contact);
	ui.showAddressLineEdit->setText(u.address);
	ui.showBalanceLineEdit->setText(QString::number(u.balance, 10, 1));
}

void userWindow::onChargePushButtonClicked()
{
	QString res = QString::number(u.balance + ui.chargeLineEdit->text().toDouble(), 10, 1);
	QStringList qsl = { "ID",u.ID,"balance",res };
	i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::USER, qsl);
	if (id.modifyOperation(i))
	{
		u.balance = res.toDouble();
		QMessageBox::information(nullptr, "提示", "充值成功");
	}
	else
	{
		QMessageBox::information(nullptr, "错误", "充值失败");
	}
}
