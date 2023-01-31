#include "transperant.h"

#include <QDebug>
#include <QPainter>
#include <QPainterPath>

static QPainterPath DrawPopWindow(QRect rect, int radius = 0, int inlineWeight = 0) {

	rect.adjust(inlineWeight,inlineWeight,-inlineWeight,-inlineWeight);
	int trigangleWidth = rect.width()/5;
	QPainterPath topTriangle;
	if(radius != 0) radius = radius/2;
	topTriangle.addRoundedRect(QRect(0,0,trigangleWidth,trigangleWidth), radius, radius);

//	qreal hip = sqrt((trigangleWidth * trigangleWidth) + (trigangleWidth * trigangleWidth));
	qreal hip = sqrt(pow(trigangleWidth,2) + pow(trigangleWidth,2));
	int location = rect.width()/2 - hip/2;
	topTriangle = QTransform()
				 .translate(location,(trigangleWidth/2 + trigangleWidth/5))
				 .rotate(-45)
				 .map(topTriangle);

	QPainterPath mainRect;
	mainRect.addRoundedRect(rect.adjusted(0,trigangleWidth/2,0,0), radius, radius);

	return mainRect + topTriangle;
}

Transperant::Transperant(QWidget *parent)
	: QWidget(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
{
	resize(300,600);
	setAttribute(Qt::WA_TranslucentBackground);
	setMouseTracking(true);


}

void Transperant::paintEvent(QPaintEvent*event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	int iw = 5;

	QPainterPath path = DrawPopWindow(this->rect(),24, iw);
	painter.fillPath(path, Qt::red);

	QPainterPath inlinePath = path;

	QColor border = isMouseOver ? Qt::white : Qt::red;
	border.setAlpha(250);
	painter.setPen(QPen(border, iw, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
	painter.drawPath(inlinePath);
	QWidget::paintEvent(event);

}


void Transperant::enterEvent(QEnterEvent*event)
{
    qDebug() << "inside ";
	isMouseOver = true;
	update();
    QWidget::enterEvent(event);
}

void Transperant::leaveEvent(QEvent*event)
{
	isMouseOver = false;
	update();
    qDebug() << "outside ";
    QWidget::leaveEvent(event);

}
