#ifndef BATTLEWIDGET_H
#define BATTLEWIDGET_H

#include <QWidget>
#include <QSharedPointer>
#include <QTimer>
#include "cell.h"
#include "field.h"
#include "tabOfInformation.h"
#include "infoTabView.h"
#include "fieldView.h"

namespace Ui {
class BattleWidget;
}

class BattleWidget : public QWidget
{
	Q_OBJECT

public:
	explicit BattleWidget(QWidget *parent = 0);
	~BattleWidget(){}

	void setMessage(QString text);
	void showPlayerField(QSharedPointer<Field> field);
	void showEnemyField(QSharedPointer<Field> field);
	void showInfoTab(QSharedPointer<TabOfInformation> infoTab);
	void setTime(int time);
	void hideTimer();

	private:
	QSharedPointer<Ui::BattleWidget> ui;
	QTimer timer;

	private slots:
	void decTime();
};

#endif // BATTLEWIDGET_H
