#include "fieldView.h"

FieldView::FieldView()
{
	mField = QSharedPointer<Field>(new Field);
	connect(mField.data(), SIGNAL(shipOnCells(int,int)), this, SIGNAL(placeShip(int,int)));
	connect(mField.data(), SIGNAL(playerAttackCell(int)), this, SIGNAL(attack(int)));
	connect(mField.data(), SIGNAL(deleteShip(int)), this, SIGNAL(deleteShip(int)));
	connect(mField.data(), SIGNAL(setFirstArrows(int)), this, SIGNAL(setFirstArrows(int)));
	connect(mField.data(), SIGNAL(setNextArrow(int)), this, SIGNAL(setNextArrow(int)));
}

QSharedPointer<Field> FieldView::getField()
{
	return mField;
}

void FieldView::showAttackStatus(AttackStatus status)
{
	mField->showAttackStatus(status);
}

void FieldView::showResult(Players player)
{
	mField->showResult(player);
}

void FieldView::addImage(int id, ImageID iD)
{
	mField->addImage(id, iD);
}

void FieldView::removeImageFromCell(int id)
{
	mField->removeImageFromCell(id);
}

void FieldView::setEnabled(bool enabled)
{
	mField->setEnabled(enabled);
}

void FieldView::repaint(int id, Textures texture)
{
    mField->paintCell(id, texture);
}
