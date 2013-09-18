#pragma once
#include <QObject>
#include <QSharedPointer>

#include "ship.h"
#include "gameField.h"
#include "playerField.h"
#include "fleetFactory.h"
#include "fleetInstaller.h"
#include "view.h"

/**
  * Player is a inherited class for all implementation of players (human, AI etc).
  */
class Player : public QObject
{
    Q_OBJECT
public:
	explicit inline Player(const QSharedPointer<GameField> &plrField,
						   const QSharedPointer<GameField>& enmField,
						   QObject* parent = 0);
    virtual ~Player() {}

    /**
      * Check does player lose or his fleet still alive.
      */
    inline bool lose();
    /**
      * Create fleet using FleetFactory object.
      */
    //inline void createFleet(const FleetFactory& factory);
    /**
      * Slot intall player fleet on field.
      */
    virtual void installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller) = 0;
signals:
    /**
      * This signal must be emitted when player chose a cell to attack (id is an identifeir of a cell).
      * Player can emit this signal only after turn() slot was called,
      * and after this wait until turn() will called again.
      * (otherwise game will crash and we all gonna die!!!).
      */
    void turnMade(int id, AttackStatus turnResult);
    /**
      * This signal must be emitted when player finished the installing of his fleet and ready to battle.
      */
    void fleetInstalled(Player* sender);
    /**
      * After player recieves information about enemy turn, he emits this signal with result of attack.
      */
    //void attackResult(AttackStatus res);
public slots:
    void autoInstallFleet(const QSharedPointer<FleetInstaller> &fleetInstaller);
    /**
      * This slot called by GameMaster to offer player make his choise (choose a cell for attack).
      */
    virtual void turn() = 0;
    /**
      * This slot called by GameMaster to inform player about results of his turn.
      */
    //inline void turnResult(AttackStatus attackResult);
    /**
      * This slot called by GameMaster to inform player about enemy turn
      * (actually, about what cell being attacked).
      */
    inline void enemyTurn(int id);
    /**
      * Choose random cell and attack it.
      * This slot called by GameMaster after timeout.
      */
    void randomTurn();
protected:
    /**
      * Accessory method. It attack enemy cell with received id and emit signal turnMade().
      * Implementation of turn() slot can call this method instead of emit turnMade().
      */
    inline void attack(int id);
    /**
      * Set the summary fleet health of player by fleet.
      */
    inline void setFleetHealth(const QVector<FleetInstaller::ptrShip>& fleet);

    /**
      *
      */
    void randomInstallFleet(const QSharedPointer<FleetInstaller> &fleetInstaller);
    /**
      *
      */
    int chooseRandomCell();

    QSharedPointer<GameField> myField;

    QSharedPointer<GameField> enemyField;

    //typedef QSharedPointer<Ship> ptrShip;
    //QVector<ptrShip> fleet;
    /**
      * Summary health of fleet, defines the number of hits after which player will lose.
      */
    int fleetHealth;
};

inline Player::Player(const QSharedPointer<GameField>& plrField,
                      const QSharedPointer<GameField>& enmField,
                      QObject *parent):
    QObject(parent),
    fleetHealth(0),
    myField(plrField),
    enemyField(enmField)
{
}

inline bool Player::lose()
{
    return (fleetHealth == 0);
}

/*
inline void Player::turnResult(AttackStatus attackResult)
{
    enemyField.attackResult(attackResult);
}
*/

inline void Player::enemyTurn(int id)
{
    if (myField->getShip(id) != NULL)
    {
        --fleetHealth;
    }
}

inline void Player::attack(int id)
{
    emit turnMade(id, enemyField->attack(id));
}

void Player::setFleetHealth(const QVector<FleetInstaller::ptrShip> &fleet)
{
    fleetHealth = 0;
    for (int i = 0; i < fleet.size(); i++)
    {
        fleetHealth += fleet[i]->health();
    }
}

inline void Player::autoInstallFleet(const QSharedPointer<FleetInstaller> &fleetInstaller)
{
    randomInstallFleet(fleetInstaller);
}
