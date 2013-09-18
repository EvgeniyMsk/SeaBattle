#pragma once
#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <QObject>
#include <QTime>

#include "types.h"
#include "player.h"


/**
  * Abstract class for two types of AIplayer - smart and simple.
  */
class AIPlayer : public Player
{
    Q_OBJECT
public:
	explicit AIPlayer(const QSharedPointer<GameField> &plrField,
					  const QSharedPointer<GameField>& enmField,
					  QObject *parent = 0);

    virtual void installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller) = 0;
    virtual ~AIPlayer()
    {}
protected:
    int tryToKill(int id);
    int attackedCells[3];
    void clear();
    Direction direction;
    AttackStatus lastAttackResult;
    // I still have no idea how and where from to get it
    //bool successShot;
    bool isWounded;
    int lastAttackedCell;
    static const int delay;
    int cnt;

public slots:

    virtual void turn() = 0;
};

#endif // AIPLAYER_H
