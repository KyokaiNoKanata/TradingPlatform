#include "calculatorWindow.h"

calculatorWindow::calculatorWindow(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
}

calculatorWindow::~calculatorWindow()
{
}

void calculatorWindow::onCalculateButtonClicked()
{
	ui.outputLineEdit->setText(c.calculate(ui.inputLineEdit->text()));
}
