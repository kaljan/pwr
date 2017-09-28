#ifndef INPUTVALUELIST_H
#define INPUTVALUELIST_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

class InputValueList : public QWidget
{
	Q_OBJECT
public:
	explicit InputValueList(QWidget *parent = 0);

	void addItem(const QString &title);
	void addItems(const QStringList &title);

signals:
	void itemValueChanged(int item, double value);

private slots:
	void on_itemTextChanged(const QString &text);

private:
	int itemCount;

	QGridLayout *grid;
	QVector<QLabel *> itemTitle;
	QVector<QLineEdit *> itemInputLine;

	void setGrid(void);

};

#endif // INPUTVALUELIST_H
