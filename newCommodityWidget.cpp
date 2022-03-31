#include "newCommodityWidget.h"

newCommodityWidget::newCommodityWidget(QString ID, QWidget *parent) : QWidget(parent)
{
	this->ID = ID;
	ui.setupUi(this);
}

newCommodityWidget::~newCommodityWidget()
{
}

void newCommodityWidget::onPushButtonClicked()
{
	QString name = ui.nameLineEdit->text(),
			price = ui.priceLineEdit->text(),
			quantity = ui.quantityLineEdit->text(),
			info = ui.infoLineEdit->text();
	if (name.isEmpty())
	{
		QMessageBox::information(nullptr, "错误", "名称不能为空");
	}
	else if (price.isEmpty())
	{
		QMessageBox::information(nullptr, "错误", "价格不能为空");
	}
	else if (quantity.isEmpty())
	{
		QMessageBox::information(nullptr, "错误", "数量不能为空");
	}
	else if (info.isEmpty())
	{
		QMessageBox::information(nullptr, "错误", "描述不能为空");
	}
	else
	{
		cm.readFile();
		QStringList qsl = {cm.getNextID(), name, price, quantity, info, ID, qdt.currentDateTime().toString("yyyy-MM-dd"), "销售中"};
		i = ig.generate(instructionGenerator::INSERT, instructionGenerator::COMMODITY, qsl);
		if (id.modifyOperation(i))
		{
			QMessageBox::information(nullptr, "提示", "上架成功");
		}
		else
		{
			QMessageBox::information(nullptr, "错误", "存在同名商品");
		}
	}
}
