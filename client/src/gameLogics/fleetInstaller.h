#ifndef FLEETINSTALLER_H
#define FLEETINSTALLER_H

#include <QObject>
#include <QSharedPointer>
#include <QPair>
#include <QVector>
#include <QMetaType>

#include "types.h"
#include "ship.h"
#include "gameField.h"
#include "infoTabView.h"

/**
  * This class places player's fleets before battle.
  */
class FleetInstaller : public QObject
{
    Q_OBJECT
public:
    typedef QSharedPointer<Ship> ptrShip;
    /**
      * This enum contains statuses of placement of ship.
      */
    Q_ENUMS(PlacementStatus);
    enum PlacementStatus
    {
        OK,
        UNCORRECT_COORDINATES,
        NOT_LINE,
        HAVE_NOT_SHIP,
        CELL_OCCUPIED
    };

    typedef QPair<int, int> CellPair;

    FleetInstaller(QVector<ptrShip> playerFleet,
                   const QSharedPointer<GameField>& playerField,
                   const QSharedPointer<InfoTabView>& _fleetInfoTab);

    QVector<ptrShip> getFleet() const;
	/**
	  * This method delete all ship on field.
	  */
	void clear();

signals:
    /**
      * Signal emitted after shipPlaced() slot ended work.
      * Signal contains result of last try to place ship on cells.
      */
	void placementResult(PlacementStatus res);
    /**
      * This signal emits when all fleet was correctly installed.
      */
    void fleetInstalled();
    //void shipPlacedSuccesfully(NameOfShips nameOfShip, int difference);
public slots:
    /**
      * This slot informs object about a try to place ship on cells kept in QVector.
      * It might connect to view object for human player or to other method for generate fleet for ai.
      * Slot emits signal placementResult() with status of this try to place ship.
      */
    PlacementStatus shipPlaced(int firstId, int secondId);
    /**
      * This slot remove the ship from field if cell with recieved id contained some ship.
      */
    void deleteShip(int id);
private slots:
    /**
      * Check, was all ships in fleet installed on field.
      * Return true if it's ok and emit fleetInstalled() signal.
      */
    bool checkIsFleetReady();
private:
    enum Orientation
    {
        CURVE,
        VERTICAL,
        HORIZONTAL
    };

    /**
      * Return positioning of ship defined by pair of ids of cells.
      */
    Orientation orientation(CellPair cells);
    /**
      * Pick ship from fleet with length defined by pair of ids of cells and positioning.
      * If there isn't suited ship in fleet, it returns null pointer.
      */
    ptrShip pickShip(CellPair cells, Orientation orn);
	int positionOfShip(QVector<QSharedPointer<Ship> > vector, const QSharedPointer<Ship> ship);

    QVector<ptrShip> fleet;
    QSharedPointer<GameField> field;
    QSharedPointer<InfoTabView> fleetInfoTab;
	QVector<QSharedPointer<Ship> > existingFleet;

};

Q_DECLARE_METATYPE(FleetInstaller::PlacementStatus);



#endif // FLEETINSTALLER_H
