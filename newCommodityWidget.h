#pragma once

#include <QWidget>
#include <QMessageBox>
#include "instructionGenerator.h"
#include "instructionDecoder.h"
#include "ui_newCommodityWidget.h"

class newCommodityWidget :public QWidget
{
	Q_OBJECT

public:
	newCommodityWidget(QString ID, QWidget* parent = Q_NULLPTR);
	~newCommodityWidget();

public slots:
	void onPushButtonClicked();

private:
	Ui::newCommodityWidget ui;
	QString ID;
	QString i;
	QDateTime qdt;
	commodityManager cm;
	instructionGenerator ig;
	instructionDecoder id;
};
