#include "window.h"

Window::Window(QWidget *parent)
	: QWidget(parent)
{
	grid = new QGridLayout(this);
	inputValueList = new InputValueList(this);
	text = new QTextEdit(this);
	e24_box = new E24SpinBox(this);

	text->setReadOnly(true);

	QStringList list;
	list << "LED current" << "LED power" << "Input voltage";

	inputValueList->addItems(list);

	grid->addWidget(inputValueList, 0, 0);
	grid->addWidget(e24_box, 1, 0);
	grid->addWidget(text, 0, 1, 3, 1);

	setLayout(grid);

	connect(inputValueList, SIGNAL(itemValueChanged(int,double)),
		this, SLOT(on_valueChanged(int,double)));

	connect(e24_box, SIGNAL(valueChanged(double)),
		this, SLOT(on_e24_changed(double)));
}

void Window::on_valueChanged(int item, double value)
{
	text->setText(QString("item: %1; value: %2").arg(item).arg(value));
}

void Window::on_e24_changed(double value)
{
	text->setText(QString("%1").arg(value, 3, 'f', 1));
}
