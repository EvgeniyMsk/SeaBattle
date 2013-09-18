#ifndef SHIP_H
#define SHIP_H

#include <QObject>
#include <QVector>

/**
  * Inherited class for all kindes of ships.
  */
class Ship : public QObject
{
    Q_OBJECT
public:
	void appedIdOfPart(int id);
	QVector<int> getCoordinate();
	void clearCoordinate();
    virtual ~Ship() {}
    virtual int damage() = 0;
    virtual int health() const = 0;
    virtual int size() const = 0;
private:
	QVector<int> coordinates;
};


#endif // SHIP_H
