#include "gameMaster.h"

GameMaster::GameMaster(const QSharedPointer<View>& _view,
                       QObject* parent):
    QObject(parent),
    playerField(NULL),
    enemyField(NULL),
    player(NULL),
    enemy(NULL),
    view(_view)
{
	playerField = QSharedPointer<GameField>(new PlayerField(view->getPlayerFieldView()));
    enemyField = QSharedPointer<GameField>(new GameField(view->getEnemyFieldView()));

	player = QSharedPointer<Player>(new HumanPlayer(playerField, enemyField
													, view->getPlayerFieldView()
													, view->getEnemyFieldView(), view->getInfoTabView()));
    enemy = QSharedPointer<Player>(new AIPlayerSimple(enemyField, playerField));
}

void GameMaster::startGame()
{
    connect(player.data(), SIGNAL(turnMade(int, AttackStatus)), this, SLOT(informOpponent(int, AttackStatus)));
    connect(enemy.data(), SIGNAL(turnMade(int, AttackStatus)), this, SLOT(informOpponent(int, AttackStatus)));
    connect(player.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));
    connect(enemy.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));

    view->showPlayerField();
    view->getPlayerFieldView()->setEnabled(true);
    view->showInfoTab();

    view->setMessage("Install fleet");
    QSharedPointer<FleetInstaller> playerInst(new FleetInstaller(FleetFactory::createFleet(),
                                                                 playerField, view->getInfoTabView()));
    player->installFleet(playerInst);

    QSharedPointer<FleetInstaller> enemyInst(new FleetInstaller(FleetFactory::createFleet(),
                                             enemyField, QSharedPointer<InfoTabView>(NULL)));
    enemy->installFleet(enemyInst);

    turnedPlayer = player;
    waitingPlayer = enemy;
}

void GameMaster::playerReadyToBattle(Player* sender)
{
    static bool isFirst = true;
    if (player == sender)
    {
        disconnect(player.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));
    }
    else if (enemy == sender)
    {
        disconnect(enemy.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));
    }
    if (!isFirst)
    {
        view->showEnemyField();
        view->getEnemyFieldView()->setEnabled(true);
        view->getPlayerFieldView()->setEnabled(false);
        offerTurn();
    }
    isFirst = false;
}

void GameMaster::offerTurn()
{
    if (turnedPlayer == player){

        view->setMessage("Your Turn");
	} else{
        view->setMessage("Enemy Turn");

	}
    turnedPlayer->turn();
}

void GameMaster::informOpponent(int id, AttackStatus turnResult)
{
    waitingPlayer->enemyTurn(id);
    nextTurn(turnResult);
}

/*
void GameMaster::informPlayer(AttackStatus attackResult)
{
    turnedPlayer->turnResult(attackResult);
    nextTurn(attackResult);
}
*/

void GameMaster::nextTurn(AttackStatus turnResult)
{
    // if result of current turn NOT_ATTACKED then something goes wrong
    if (turnResult == NOT_ATTACKED)
    {
        // to do: throw an exception
    }
    else if (turnResult == MISS)
    {
        // swap the turned and waiting players
        ptrPlayer tmp = turnedPlayer;
        turnedPlayer = waitingPlayer;
        waitingPlayer = tmp;
    }
    else
    {
        // if ship was wounded or killed then
        // next turn make the same player
    }

    if (player->lose() || enemy->lose())
    {
        // to do: end game and send message about win.
    }
    else
    {
        // else continue game
        offerTurn();
    }
}
