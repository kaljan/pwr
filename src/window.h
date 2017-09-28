#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "inputvaluelist.h"
#include <QGridLayout>
#include <QTextEdit>
#include "e24spinbox.h"

class Window : public QWidget
{
	Q_OBJECT
public:
	explicit Window(QWidget *parent = 0);

private slots:
	void on_valueChanged(int item, double value);
	void on_e24_changed(double value);
private:
	QGridLayout *grid;
	InputValueList *inputValueList;
	QTextEdit *text;
	E24SpinBox *e24_box;
};

#endif // WINDOW_H
