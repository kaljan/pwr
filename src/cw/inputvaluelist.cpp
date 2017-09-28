#include "inputvaluelist.h"

InputValueList::InputValueList(QWidget *parent)
	: QWidget(parent)
	, itemCount(0)
{
	setGrid();
}

void InputValueList::setGrid()
{
	grid = new QGridLayout(this);
	setLayout(grid);
	grid->setColumnStretch(1, 1);
}

void InputValueList::addItem(const QString &title)
{
	QLabel *label = new QLabel(title, this);
	QLineEdit *line = new QLineEdit(this);

	itemTitle.append(label);
	itemInputLine.append(line);

	grid->addWidget(label, itemCount, 0);
	grid->addWidget(line, itemCount, 1);
	grid->setAlignment(label, Qt::AlignCenter);

	itemCount++;

	connect(line, SIGNAL(textChanged(QString)),
		this, SLOT(on_itemTextChanged(QString)));
}

void InputValueList::addItems(const QStringList &title)
{
	foreach (QString str, title) {
		addItem(str);
	}
}

void InputValueList::on_itemTextChanged(const QString &text)
{
	int item = 0;
	double value = 0;
	bool ok = false;

	value = text.toDouble(&ok);
	if (ok == false) {
		return;
	}

	for (item = 0; item < itemCount; item++) {
		if (sender() == itemInputLine.at(item)) {
			break;
		}
	}

	emit itemValueChanged(item, value);
}



