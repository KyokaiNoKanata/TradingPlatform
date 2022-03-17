#pragma once

#include <QWidget>
#include <QMessageBox>
#include "instructionGenerator.h"
#include "instructionDecoder.h"
#include "ui_commodityModifyWidget.h"

class commodityModifyWidget :public QWidget
{
	Q_OBJECT

public:
	commodityModifyWidget(QString ID, QWidget* parent = Q_NULLPTR);
	~commodityModifyWidget();

private slots:
	void onPriceModifyPushButtonClicked();
	void onInfoModifyPushButtonClicked();

private:
	Ui::commodityModifyWidget ui;
	QString ID;
	QString i;
	instructionGenerator ig;
	instructionDecoder id;
};
