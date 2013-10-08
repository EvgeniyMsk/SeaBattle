#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <QObject>
#include <QSharedPointer>
#include <QTimer>

#include "player.h"
#include "humanPlayer.h"
#include "networkHumanPlayer.h"
#include "remotePlayer.h"
#include "aiPlayerSimple.h"
#include "playerField.h"
#include "audioPlayer.h"
#include "LogAndChat.h"

class GameMaster : public QObject
{
    Q_OBJECT
public:
    GameMaster(GameType type,
               const QSharedPointer<InterfaceBattleWidget>& _view,
               const QSharedPointer<Client>& _client,
               QObject* parent = 0);

    /**
      * Method start the game.
      */
    void startGame();
private slots:
    /**
      *
      */
    void playerReadyToBattle(Player* sender);
    /**
      * Offer to make turn to turned player.
      */
    void offerTurn();
    /**
      * Inform waited player that player attacked the cell with passed id.
      * Before return, call nextTurn() slot.
      */
    void informOpponent(int id, AttackStatus turnResult);
    /**
      * Inform turned player about the result of attack.
      */
    //void informPlayer(AttackStatus attackResult);
    /**
      * This slot ends current turn and start the new one.
      */
    void nextTurn(AttackStatus turnResult);
private:
    typedef QSharedPointer<Player> ptrPlayer;
    QSharedPointer<GameField> playerField;
    QSharedPointer<GameField> enemyField;
	QSharedPointer<LogAndChat> mChat;
    ptrPlayer player;
    ptrPlayer enemy;

    ptrPlayer turnedPlayer;
    ptrPlayer waitingPlayer;

	QSharedPointer<InterfaceBattleWidget> view;

    QTimer turnTimer;
    QSharedPointer<AudioPlayer> audioPlayer;

    QSharedPointer<Client> client;

    static const int turnTimeout;

	int plrFleet;
	int enemyFleet;
};

#endif // GAMEMASTER_H
