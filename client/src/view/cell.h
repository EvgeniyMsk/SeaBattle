#pragma once
#include <QGraphicsItem>
#include <QPainter>
#include <QPointF>
#include "types.h"

class Cell: public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	Cell(int x, int y);
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void changeStatusOfCell(Textures texture = EMPTY);
signals:
	void attacked(int id);
	void getCoordinate(QPointF first, QPointF second);
	void deleteShip(int id);
	void coordinatesOfMouseNow(int id);
	void setArrows(int id);
private:
	int x;
	int y;
	QPointF first;
	QString mTexture;
};
