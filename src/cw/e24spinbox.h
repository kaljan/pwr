#ifndef E24SPINBOX_H
#define E24SPINBOX_H

#include <QDoubleSpinBox>

const double std_nomial_E24[24] = {
	1.0, 1.1, 1.2, 1.3,
	1.5, 1.6, 1.8, 2.0,
	2.2, 2.4, 2.7, 3.0,
	3.3, 3.6, 3.9, 4.3,
	4.7, 5.1, 5.6, 6.2,
	6.8, 7.5, 8.2, 9.1
};

class E24SpinBox : public QDoubleSpinBox
{
	Q_OBJECT
public:
	explicit E24SpinBox(QWidget *parent = 0)
		: QDoubleSpinBox(parent)
		, index(0)
	{
		setValue(std_nomial_E24[index]);
	}

protected:
	void stepBy(int steps) {
		index += steps;
		index = qBound(0, index, 23);
		setValue(std_nomial_E24[index]);
	}


	QString textFromValue(double val) const {
		return QString("%1").arg(val, 3, 'f', 1);
	}

	double valueFromText(const QString &text) const {
		bool ok = false;
		double value = text.toDouble(&ok);
		return ((ok == true) ? value : 0);
	}
private:
	int index;

};

#endif // E24SPINBOX_H
