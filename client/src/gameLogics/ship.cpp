#include "ship.h"


QVector<int> Ship::getCoordinate()
{
	return coordinates;
}

void Ship::clearCoordinate()
{
	coordinates.clear();
}


void Ship::appedIdOfPart(int id)
{
	coordinates.append(id);
}
