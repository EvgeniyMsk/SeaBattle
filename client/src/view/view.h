#pragma once
#include <QSharedPointer>
#include "BattleWidget.h"
#include "cell.h"

class View : public QObject
{
	Q_OBJECT
public:
	View();
	~View();
	void showPlayerField();
	void showEnemyField();
	void showInfoTab();
	void setTime(int time);
	void hideTimer();
    QSharedPointer<FieldView> getPlayerFieldView();
    QSharedPointer<FieldView> getEnemyFieldView();
    QSharedPointer<InfoTabView> getInfoTabView();

public slots:
	void setMessage(QString text);

private:
	QSharedPointer<BattleWidget> mBattleWidget;
	QSharedPointer<FieldView> mPlayerField;
	QSharedPointer<FieldView> mEnemyField;
	QSharedPointer<InfoTabView> mInfoTab;
};
