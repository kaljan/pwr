#include "infoimage.h"

InfoImage::InfoImage(QWidget *parent)
	: QWidget(parent)
{

}

void InfoImage::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
}

