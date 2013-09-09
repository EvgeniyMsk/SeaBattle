#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <QObject>
#include <QTime>

#include "types.h"
#include "player.h"

/**
  * Pretty stupid implementation of AI for sea battle game. It just choose random cell on each step.
  */
class AIPlayer : public Player
{
    Q_OBJECT
public:
    explicit AIPlayer(const QSharedPointer<GameField>& plrField,
                      const QSharedPointer<GameField>& enmField,
                      QObject *parent = 0);

    void installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller);
public slots:
    /**
      * Nothing to thing about it, choose the random cell!
      */
    void turn();
};

#endif // AIPLAYER_H