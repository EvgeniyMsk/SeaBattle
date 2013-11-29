#include "player.h"

void Player::randomInstallFleet()
{
    myField->removeInstalledFleet();
    QVector<FleetInstaller::ptrShip> fleet = myField->getFleet();
	setFleetHealth(fleet);
	int size = fleet.size();

    for (int i = 0; i < fleet.size(); i++)
    {
        int max = i;
        int j = i;
        for (j = i; j < fleet.size(); j++)
        {
            if (fleet[max]->size() < fleet[j]->size())
            {
                max = j;
            }
        }
        FleetInstaller::ptrShip tmp = fleet[i];
        fleet[i] = fleet[max];
        fleet[max] = tmp;
    }

    for (int i = 0; i < fleet.size(); i++)
	{
		int shipSize = fleet[i]->size();
		bool isHorizontal = true;
		int smth = qrand()% 20 - qrand() % 20;
		if (smth > 0)
		{
			isHorizontal = false;
		}

		int row = 0;
		int col = 0;
		int first = 0;

		int second = 0;
        PlacementStatus status = OK;
		do
		{
			do
			{
				row = qrand() % FIELD_ROW_NUM;
			}
			while (!isHorizontal && (row > (FIELD_ROW_NUM - shipSize)));
			do
			{
				col = qrand() % FIELD_COL_NUM;
			}
			while(isHorizontal && (col > (FIELD_COL_NUM - shipSize)));

			QPair<int, int> point1(row, col);
			QPair<int, int> point2(row, col);

			if (shipSize == 1){
				first = getIdByCoordinates(point1);
				second = getIdByCoordinates(point2);
                status = myField->setShip(first, second);
			}else {
				if (isHorizontal)
				{
                    point2.second += shipSize - 1;
				}
				else
				{
					point2.first += shipSize - 1;
				}
				first = getIdByCoordinates(point1);
				second = getIdByCoordinates(point2);
                status = myField->setShip(first, second);
			}
        } while((status != OK) &&
                (status != HAVE_NOT_SHIP));
	}
}

int Player::chooseRandomCell()
{
    int id = 0;
    bool res = false;
    do
    {
        id = qrand() % (FIELD_ROW_NUM * FIELD_COL_NUM - 1);
        res = enemyField->attackable(id);
    }
    while (!res);
    return id;
}

void Player::randomTurn()
{
    int id = chooseRandomCell();
    emit turnMade(id, enemyField->attack(id));
}
