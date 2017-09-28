#ifndef INFOIMAGE_H
#define INFOIMAGE_H

#include <QWidget>
#include <QPainter>
#include <QPen>

class InfoImage : public QWidget
{
	Q_OBJECT
public:
	explicit InfoImage(QWidget *parent = 0);

public slots:

	void setPen(const QPen &pen) {
		this->pen = pen;
		update();
	}

protected:

	void paintEvent(QPaintEvent *);

private:

	QPen pen;
};

#endif // INFOIMAGE_H
