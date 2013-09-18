#include "view.h"
#include <QDebug>
View::View()
{
	mBattleWidget = QSharedPointer<BattleWidget>(new BattleWidget);
	mPlayerField = QSharedPointer<FieldView>(new FieldView);
	mEnemyField = QSharedPointer<FieldView>(new FieldView);
	mInfoTab = QSharedPointer<InfoTabView>(new InfoTabView);
	mBattleWidget.data()->show();
}

View::~View()
{
}

void View::showPlayerField()
{
	mBattleWidget->showPlayerField(mPlayerField->getField());
}

void View::showEnemyField()
{
	mBattleWidget->showEnemyField(mEnemyField->getField());
}

void View::showInfoTab()
{
	mBattleWidget->showInfoTab(mInfoTab->getInfoTab());
}

void View::setTime(int time)
{
	mBattleWidget->setTime(time);
}

void View::hideTimer()
{
	mBattleWidget->hideTimer();
}

QSharedPointer<FieldView> View::getPlayerFieldView()
{
	return mPlayerField;
}

QSharedPointer<FieldView> View::getEnemyFieldView()
{
	return mEnemyField;
}

QSharedPointer<InfoTabView> View::getInfoTabView()
{
	return mInfoTab;
}

void View::setMessage(QString text)
{
	mBattleWidget->setMessage(text);
}

