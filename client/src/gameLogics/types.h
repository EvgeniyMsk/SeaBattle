#ifndef TYPES_H
#define TYPES_H
#include <QPointF>
#include <QPair>
#include <QSharedPointer>
namespace Orientation {
enum Orient{
	UP,
	RIGHT,
	DOWN,
	LEFT
};
}


enum Direction {
	LEFT,
	DOWN,
	RIGHT,
	HIGH
};

enum AttackStatus
{
    NOT_ATTACKED,
    MISS,
    WOUNDED,
    KILLED
};

enum NameOfShips{
	BOAT_SCOUT,
	DESTROYER,
	CRUISER,
	AEROCARRIER
};

enum Textures
{
    EMPTY,
    MISS_CELL,
    SHIP_POOP_VERTICAL,
    SHIP_BOW_VERTICAL,
    SHIP_DECK_VERTICAL,
    SHIP_POOP_HORIZONTAL,
    SHIP_BOW_HORIZONTAL,
    SHIP_DECK_HORIZONTAL,
	SHIP_POOP_VERTICAL_BURN,
	SHIP_BOW_VERTICAL_BURN,
	SHIP_DECK_VERTICAL_BURN,
	SHIP_POOP_HORIZONTAL_BURN,
	SHIP_BOW_HORIZONTAL_BURN,
	SHIP_DECK_HORIZONTAL_BURN,
	SHIP_SINGLE_BURN,
	SHIP_SINGLE,
    SHIP_DAMAGED,
	SHIP_KILLED,
	WRECK
};

enum Players{
	NONE,
	YOU,
	ENEMY
};

enum ImageID{
	ARROW_UP,
	ARROW_DOWN,
	ARROW_R,
	ARROW_L,
	ARROW_IN_ITSELF,
	FIRT_POINT
};

const int FIELD_ROW_NUM = 10;
const int FIELD_COL_NUM = 10;
const int DATA_KEY = 15;

const int sizeOfCube = 300;
const int sizeOfCubeDivTen = 30;

inline QPair<int, int> coordinates(int id)
{
    return QPair<int, int>(id / FIELD_ROW_NUM, id % FIELD_COL_NUM);
}

inline int getIdByCoordinates(const QPair<int, int>& point)
{
    return point.first * FIELD_ROW_NUM + point.second;
}

inline int getIdByCoordinates(int row, int col)
{
    return row * FIELD_ROW_NUM + col;
}

inline QPointF getQPointFByID(int id)
{
	return QPointF(id % FIELD_COL_NUM * (sizeOfCube / FIELD_ROW_NUM)
				   , id / FIELD_ROW_NUM * (sizeOfCube / FIELD_ROW_NUM));
}

inline bool checkCoord(int x, int y)
{
	return !((x < 0) || (x >= FIELD_ROW_NUM) || (y < 0) || (y >= FIELD_COL_NUM));
}
#endif // TYPES_H


