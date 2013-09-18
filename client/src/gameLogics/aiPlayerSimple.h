
#pragma once



#include "aiPlayer.h"
/**
  * Simple computer player, random choose and correctness check.
  */

class AIPlayerSimple : public AIPlayer
{
    Q_OBJECT
public:

    explicit AIPlayerSimple(const QSharedPointer<GameField>& plrField,
                      const QSharedPointer<GameField>& enmField,
                      QObject *parent = 0);
     void installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller);
private:
	 void changeDirection();
public slots:
    /**
      * Nothing to thing about it, choose the random cell!
      */
    void turn();
private slots:
    /**
      * Subsidiary slot for the delay attack
      */
    void delayTurn();
};

