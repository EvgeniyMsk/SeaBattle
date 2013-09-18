#include "field.h"
#include "ui_field.h"
#include <QDebug>
#include <QPixmap>


Field::Field(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Field)
{
	ui->setupUi(this);
	this->setMaximumSize(sizeOfCube + 40, sizeOfCube + 40);
	this->setMinimumSize(sizeOfCube + 40, sizeOfCube + 40);
	ui->graphicsView->setMaximumSize(sizeOfCube + 10, sizeOfCube + 10);
	ui->graphicsView->setMinimumSize(sizeOfCube + 10, sizeOfCube + 10);
	mScene = new QGraphicsScene;
	mScene->setSceneRect(0, 0, sizeOfCube, sizeOfCube);
	int x = sizeOfCube / 10;
	int y = sizeOfCube / 10;
	field.resize(100);
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 10; j++){
			Cell *item = new Cell(x, y);
			field[(i - 1) * 10 + j - 1] = item;
			item->setData(DATA_KEY, (i - 1) * 10 + j - 1);
			item->setPos((j - 1) * x, (i - 1) * y);
			connect(item, SIGNAL(attacked(int)), this, SLOT(cellWasAttacked(int)));\
			connect(item, SIGNAL(getCoordinate(QPointF,QPointF)), this, SLOT(getCoordinate(QPointF,QPointF)));
			connect(item, SIGNAL(deleteShip(int)), this, SLOT(deleteShipOnCell(int)));
			connect(item, SIGNAL(setArrows(int)), this, SIGNAL(setFirstArrows(int)));
			connect(item, SIGNAL(coordinatesOfMouseNow(int)), this, SIGNAL(setNextArrow(int)));
			mScene->addItem(item);
		}
	}
	ui->graphicsView->setScene(mScene);

}

void Field::paintCell(int id, Textures texture)
{
	field.at(id)->changeStatusOfCell(texture);
}

void Field::showAttackStatus(AttackStatus status)
{
	QPixmap message;
	switch (status) {
	case MISS:
		message = QPixmap(":/pictures/MISS.png");
		break;
	case WOUNDED:
		message = QPixmap(":/pictures/WOUNDED.png");
		break;
	case KILLED:
		message = QPixmap(":/pictures/KILLED.png");
		break;
	}
	itemForMessage = QSharedPointer<QGraphicsItem>(mScene->addPixmap(message));
	ui->graphicsView->update();
	timer.start(1000);
	connect(&timer, SIGNAL(timeout()), this, SLOT (deleteMessage()));
}

void Field::showResult(Players player)
{
	QPixmap message;
	switch (player) {
	case YOU:
		message = QPixmap(":/pictures/LOSER.jpeg");
		break;
	case ENEMY:
		message = QPixmap(":/pictures/WINNER.jpeg");
		break;
	}
	itemForEndMessage = QSharedPointer<QGraphicsItem>(mScene->addPixmap(message));
	ui->graphicsView->update();
}

Cell* Field::getCellView(int id)
{
	return field[id];
}

void Field::addImage(int id, ImageID iD)
{
	QSharedPointer<QGraphicsItem> pictureForCell;
	QPixmap arrow = QPixmap(":/pictures/arrow.png");
	QPixmap firstPoint = QPixmap(":/pictures/first point.png");
	QPixmap arrowCircle = QPixmap(":/pictures/cirle arrow.png");
	switch (iD) {
	case ARROW_DOWN:
		arrow = arrow.transformed(QTransform().rotate(qreal(180),Qt::ZAxis), Qt::FastTransformation);
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(arrow));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	case ARROW_IN_ITSELF:
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(arrowCircle));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	case ARROW_L:
		arrow = arrow.transformed(QTransform().rotate(qreal(270),Qt::ZAxis), Qt::FastTransformation);
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(arrow));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	case ARROW_R:
		arrow = arrow.transformed(QTransform().rotate(qreal(90),Qt::ZAxis), Qt::FastTransformation);
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(arrow));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	case ARROW_UP:
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(arrow));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	case FIRT_POINT:
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(firstPoint));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	}
//	pictureForCell->setData(DATA_KEY, id);
//	picturesUnderCell.append(pictureForCell);
	picturesUnderCell[id] = pictureForCell;
	ui->graphicsView->update();
}

void Field::removeImageFromCell(int id)
{
	//int i = positionOFItem(id);
	mScene->removeItem(picturesUnderCell[id].data());
//	picturesUnderCell.remove(positionOFItem(i));
	ui->graphicsView->update();
}

Field::~Field()
{
	delete ui;
	mScene->clear();
	delete mScene;
}

void Field::cellWasAttacked(int id)
{
	emit playerAttackCell(id);
}

void Field::getCoordinate(QPointF first, QPointF second)
{
	QList<QGraphicsItem*> list = mScene->items(first);
	QList<QGraphicsItem*> list2 = mScene->items(second);
	QGraphicsItem *firstCell;
	QGraphicsItem *secondCell;
	int i = 0;
	bool condition = false;
	do{
		qDebug() << list.at(i)->data(DATA_KEY).toInt();
		condition = list.at(i)->data(DATA_KEY).toInt();
		i++;
	}while (!condition);
	condition = false;
	firstCell = list.at(i - 1);
	i = 0;
	do{
		qDebug() << list2.at(i)->data(DATA_KEY).toInt();
		condition = list2.at(i)->data(DATA_KEY).toInt();
		i++;
	}while (!condition);
	secondCell = list2.at(i - 1);
	emit shipOnCells(firstCell->data(DATA_KEY).toInt(), secondCell->data(DATA_KEY).toInt());
}

void Field::deleteShipOnCell(int id)
{
	emit deleteShip(id);
}

void Field::deleteMessage()
{
	disconnect(&timer, SIGNAL(timeout()), this, SLOT (deleteMessage()));
	timer.stop();
	mScene->removeItem(itemForMessage.data());
	ui->graphicsView->update();
}

int Field::positionOFItem(int id)
{
//	for (int i = 0; i < picturesUnderCell.size(); i++){
//		if (picturesUnderCell.at(i)->data(DATA_KEY).toInt() == id){
//			return i;
//		}
//	}
	return 0;
}
