#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <QObject>

#include "player.h"
#include "fleetInstaller.h"
#include "view.h"

// for test purpose
class HumanPlayerTest;

class HumanPlayer : public Player
{
    Q_OBJECT
public:
	explicit HumanPlayer(const QSharedPointer<GameField> &plrField,
						 const QSharedPointer<GameField>& enmField,
						 const QSharedPointer<FieldView>& _plrFieldView,
						 const QSharedPointer<FieldView>& _enmFieldView, const QSharedPointer<InfoTabView> &infoTab,
						 QObject *parent = 0);
    
    // for test purpose
    friend class HumanPlayerTest;

    /**
      *
      */
    void installFleet(const QSharedPointer<FleetInstaller>& fleetInstaller);
public slots:
    /**
      * This slot do nothing because it need to wait until player made a choise.
      */
    void turn();

private slots:
    /**
      * This slot connected with cellWasAttacked() signal of Field view.
      */
	void cellWasAttacked(int id);
    /**
      * Reemit fleetInstalled signal with this parametr.
      */
    void reEmitFleetInstalled();
	void needAutoInstallFleet();
    //void deleteShip(int id);
private:
    QSharedPointer<FieldView> plrFieldView;
    QSharedPointer<FieldView> enmFieldView;
    QSharedPointer<FleetInstaller> fleetInst;
	QSharedPointer<InfoTabView> infoTab;
	bool myTurn;
};

#endif // HUMANPLAYER_H
