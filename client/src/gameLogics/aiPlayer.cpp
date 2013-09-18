#include "aiPlayer.h"

// delay for turns of ai players in ms
const int AIPlayer::delay = 2 * 1000;

AIPlayer::AIPlayer(const QSharedPointer<GameField> &plrField,
                   const QSharedPointer<GameField> &enmField,
                   QObject *parent):
    Player(plrField, enmField, parent)
{
    for(int i = 0; i < 3; i++)
        attackedCells[i] = 0;
    cnt = 2;
    //connect(this, SIGNAL(turnMade(int)), );
    qsrand(QTime::currentTime().msec());
}

void AIPlayer::clear()
{
    for(int i = 0; i < 3; i++)
        attackedCells[i] = 0;
    cnt = 2;
}

int AIPlayer::tryToKill(int id)
 {

    // chose one of  neighboor cells

    int x = id % FIELD_ROW_NUM;
    int y = id / FIELD_COL_NUM;
    bool res = 0;
    int orintation = 0;
    int nextAttacked = 0;
    do
    {
        for (int i = 0; i < 3; i++)
        {
            if (attackedCells[i] == 0 ) //
            {
                nextAttacked = i;
                orintation = i;
                break;
            }
        }

        switch (nextAttacked)
        {
        case LEFT:
            if((x - 1 >= 0) && (enemyField->attackable(id - 1)))
            {
                nextAttacked = id - 1;
                direction = LEFT;
                break;
            }
        case DOWN:
            if ((y + 1 <= 10) && (enemyField->attackable(id + 10))
)            {
                nextAttacked = id + 10;
                direction = DOWN;
                break;
            }
        case RIGHT:
            if ((x + 1 <= 10) && (res = enemyField->attackable(id + 1)))
            {
                nextAttacked = id  + 1;
                direction = RIGHT;
                break;
            }
        case HIGH:
            if ((y - 1 >= 0) && (res = enemyField->attackable(id - 10)))
            {
                nextAttacked = id - 10;
                direction = HIGH;
                break;
            }
        }

        res = enemyField->attackable(nextAttacked); // check for cell were'nt visited earlyer
    }
    while (!res);
    attackedCells[orintation] = nextAttacked; // remember attacked cell
  //  direction = static_cast<Direction>(orintation); // remember attacking direction
    return nextAttacked;
 }

//void AIPlayer::turn()
//{
//    int id = 0;
//    bool res = false;
//    do
//    {
//        id = qrand() % (FIELD_ROW_NUM * FIELD_COL_NUM - 1);
//     //   res =  enmField. //attack(id);
//    }
//    while (!res);
//    attack(id);
//}


