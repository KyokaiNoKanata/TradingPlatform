#include "commodityModifyWidget.h"

commodityModifyWidget::commodityModifyWidget(QString ID, QWidget *parent) : QWidget(parent)
{
	this->ID = ID;
	ui.setupUi(this);
}

commodityModifyWidget::~commodityModifyWidget()
{
}

void commodityModifyWidget::onPriceModifyPushButtonClicked()
{
	QStringList qsl;
	qsl.append("ID");
	qsl.append(ID);
	qsl.append("price");
	qsl.append(ui.lineEdit->text());
	i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::COMMODITY, qsl);
	if (id.modifyOperation(i))
	{
		QMessageBox::information(nullptr, "提示", "修改成功");
	}
	else
	{
		QMessageBox::information(nullptr, "错误", "修改失败");
	}
}

void commodityModifyWidget::onInfoModifyPushButtonClicked()
{
	QStringList qsl;
	qsl.append("ID");
	qsl.append(ID);
	qsl.append("information");
	qsl.append(ui.lineEdit->text());
	i = ig.generate(instructionGenerator::UPDATE, instructionGenerator::COMMODITY, qsl);
	if (id.modifyOperation(i))
	{
		QMessageBox::information(nullptr, "提示", "修改成功");
	}
	else
	{
		QMessageBox::information(nullptr, "错误", "修改失败");
	}
}
