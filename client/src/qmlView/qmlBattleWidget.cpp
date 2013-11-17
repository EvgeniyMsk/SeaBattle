#include "qmlBattleWidget.h"
#include <QDebug>
#include <QTimer>


//i know, that this code very horrible, but...deadline and other problem make me to do this

const QString QmlBattleWidget::componentUrl = "qml/qml/Battle.qml";

QmlBattleWidget::QmlBattleWidget(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder) :
	mWidgetAppender(widgetAppeder),
	mChatAndStatus(new QmlChatAndStatus())
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mBattleWidget = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));

	timer = mBattleWidget->findChild<QObject*>("timer");
	connect(mBattleWidget.data(), SIGNAL(backPressed()), this, SIGNAL(quitDialogOkPressed()));
	connect(mBattleWidget.data(), SIGNAL(deleteMode(bool)), SLOT(handleDeleteShipMode(bool)));
	mInfoTab = QSharedPointer<QmlInfoTab>(new QmlInfoTab(mBattleWidget->findChild<QObject*>("mAutoButton")
													 ,mBattleWidget->findChild<QObject*>("mButtonReady")
													 ,mBattleWidget->findChild<QObject*>("mCountOfShip")));
	mPlrField = QSharedPointer<QmlField>(new QmlField(mBattleWidget->findChild<QObject*>("mPlrField")));
	mEnemyField = QSharedPointer<QmlField>(new QmlField(mBattleWidget->findChild<QObject*>("mEnemyField")));
}

void QmlBattleWidget::showPlayerField()
{
	// crashed here ...
	QObject* mField = mBattleWidget->findChild<QObject*>("mPlrField");
	qDebug() << mField;
	mField->setProperty("visible", true);
}

void QmlBattleWidget::showEnemyField()
{
	//to do, there we give command to start
	mBattleWidget->setProperty("isFight", true);
	mPlrField->setBattleMode(true);
	mEnemyField->setBattleMode(true);
}

void QmlBattleWidget::showInfoTab()
{
	//unused....
}

void QmlBattleWidget::setTime(int time)
{
	timer->setProperty("visible", true);
	timer->setProperty("text", time);
}

void QmlBattleWidget::hideTimer()
{
	timer->setProperty("visible", false);
}

void QmlBattleWidget::showCountersOfFleet()
{
	//unused....
}

void QmlBattleWidget::setCountOfFleet(Players plr, int count)
{
	if (plr == YOU){
		mBattleWidget->setProperty("countOfPlr", count);
	}else{
		mBattleWidget->setProperty("countOfEnemy", count);
	}
}

void QmlBattleWidget::clearItself()
{
	//to do call in children
	mBattleWidget->setProperty("isFight", false);
	mPlrField->clearItself();
	mBattleWidget->setProperty("countOfEnemy", 10);
	mBattleWidget->setProperty("countOfPlr", 10);
	mEnemyField->clearItself();
	mPlrField->setBattleMode(false);
	mEnemyField->setBattleMode(false);
}

void QmlBattleWidget::showGameBreakDialog(const QString& message)
{
	//unused....
}

void QmlBattleWidget::showQuitDialog()
{
	//unused....
}

void QmlBattleWidget::switchToPlayerField()
{
	QTimer::singleShot(1000, this, SLOT(delayedSwitchToPlayerField()));
}

void QmlBattleWidget::delayedSwitchToPlayerField()
{
	QMetaObject::invokeMethod(mBattleWidget.data(), "switchToPlayerField");
}

void QmlBattleWidget::switchToEnemyField()
{
	QTimer::singleShot(1000, this, SLOT(delayedSwitchToEnemyField()));
}

void QmlBattleWidget::delayedSwitchToEnemyField()
{
	QMetaObject::invokeMethod(mBattleWidget.data(), "switchToEnemyField");
}

void QmlBattleWidget::show()
{
	mWidgetAppender->show(mBattleWidget);
}

void QmlBattleWidget::hide()
{
	mWidgetAppender->hide(mBattleWidget);
}

QSharedPointer<InterfaceField> QmlBattleWidget::getPlayerFieldView()
{
	return mPlrField;
}

QSharedPointer<InterfaceField> QmlBattleWidget::getEnemyFieldView()
{
	return mEnemyField;
}

QSharedPointer<InterfaceInfoTab> QmlBattleWidget::getInfoTabView()
{
	return mInfoTab;
}

QSharedPointer<InterfaceChatAndStatus> QmlBattleWidget::getChatAndStatus()
{
	return mChatAndStatus;
}

void QmlBattleWidget::setMessage(QString text)
{
	//unused....
	Q_UNUSED(text)
}

void QmlBattleWidget::handleDeleteShipMode(bool isActive)
{
	mPlrField->setDeleteShipMode(isActive);
}

