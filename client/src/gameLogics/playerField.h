#pragma once
#include "gameField.h"

class PlayerField : public GameField
{
Q_OBJECT
public:
	PlayerField(const QSharedPointer<FieldView> &fieldView);
	virtual AttackStatus attack(int id);
	virtual void repaintCell(int row, int column, int partOfShip, int shipSize, bool orientation);

private:
	int firstId;
	ImageID previousIm;
	bool isEmptyAround(QPair<int, int> ID);
	QVector<bool> orientation; // can it go to UP RIGHT DOWN LEFT TO_ITSELF
	QVector<int> cellsWithArrow;

	void analyzeNextArrow(Orientation::Orient orient, ImageID iD, int id); //for QVector<bool> orientation
	void setArrow(int id, ImageID iD, int difference, Orientation::Orient orient); //for help to setFirstArrows

private slots:
	void setFirstArrows(int id);
	void setNextArrow(int id);
	void deleteAllArrows(int firstID, int secondID);
};

