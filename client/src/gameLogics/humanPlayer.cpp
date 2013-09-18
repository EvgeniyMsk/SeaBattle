#include "humanPlayer.h"

HumanPlayer::HumanPlayer(const QSharedPointer<GameField>& plrField
						, const QSharedPointer<GameField>& enmField
						, const QSharedPointer<FieldView>& _plrFieldView
						, const QSharedPointer<FieldView>& _enmFieldView
						, const QSharedPointer<InfoTabView> &infoTab
						, QObject* parent):
    Player(plrField, enmField, parent),
    plrFieldView(_plrFieldView),
    enmFieldView(_enmFieldView),
	fleetInst(NULL),
	infoTab(infoTab),
	myTurn(false)
{
    connect(enmFieldView.data(), SIGNAL(attack(int)), this, SLOT(cellWasAttacked(int)));
	connect(infoTab.data(), SIGNAL(needAutoSetting()), this, SLOT(needAutoInstallFleet()));
}

void HumanPlayer::installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller)
{
    fleetInst = fleetInstaller;
	setFleetHealth(fleetInst->getFleet());
    connect(plrFieldView.data(), SIGNAL(placeShip(int,int)), fleetInst.data(), SLOT(shipPlaced(int,int)));
    connect(plrFieldView.data(), SIGNAL(deleteShip(int)), fleetInst.data(), SLOT(deleteShip(int)));
	connect(fleetInst.data(), SIGNAL(fleetInstalled()), this, SLOT(reEmitFleetInstalled()));
	/*
    connect(fleetInstaller, SIGNAL(shipPlacedSuccesfully(NameOfShips, int))
            , view, SLOT(changeCounter(NameOfShips,int)));
    */

}

void HumanPlayer::turn()
{
    myTurn = true;
}

void HumanPlayer::cellWasAttacked(int id)
{
    if (myTurn && enemyField->attackable(id))
    {
        myTurn = false;
        attack(id);
    }
}

void HumanPlayer::reEmitFleetInstalled()
{
	emit fleetInstalled(this);
}

void HumanPlayer::needAutoInstallFleet()
{
	fleetInst->clear();
	autoInstallFleet(fleetInst);
}
