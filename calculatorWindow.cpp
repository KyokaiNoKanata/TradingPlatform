#include "calculatorWindow.h"

calculatorWindow::calculatorWindow(QWidget* parent) :QWidget(parent)
{
	this->ui.setupUi(this);
}

calculatorWindow::~calculatorWindow()
{
}

void calculatorWindow::onCalculateButtonClicked()
{
	this->ui.outputLineEdit->setText(c.calculate(this->ui.inputLineEdit->text()));
}