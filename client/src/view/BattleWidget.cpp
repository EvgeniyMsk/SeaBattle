#include "BattleWidget.h"
#include "ui_BattleWidget.h"

BattleWidget::BattleWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::BattleWidget),
	timer()
{
	ui->setupUi(this);
	ui->lcdNumber->hide();
	this->setWindowTitle(QString::fromLocal8Bit("МОРСКОЙ БОЙ"));

	timer.setSingleShot(false);
}

void BattleWidget::setMessage(QString text)
{
	ui->label->setText(QString::fromLocal8Bit(text.toLocal8Bit()));
}

void BattleWidget::showPlayerField(QSharedPointer<Field> field)
{
	ui->horizontalLayout_2->addWidget(field.data());
}

void BattleWidget::showInfoTab(QSharedPointer<TabOfInformation> infoTab)
{
	ui->horizontalLayout_2->addWidget(infoTab.data());
}

void BattleWidget::setTime(int time)
{
	disconnect(&timer, SIGNAL(timeout()), 0, 0);
	ui->lcdNumber->display(time);
	timer.start(1000);
	connect(&timer, SIGNAL(timeout()), this, SLOT(decTime()));
}

void BattleWidget::hideTimer()
{
	ui->lcdNumber->hide();
}

void BattleWidget::decTime()
{
	ui->lcdNumber->display(ui->lcdNumber->intValue() - 1);
}

void BattleWidget::showEnemyField(QSharedPointer<Field> field)
{
	ui->lcdNumber->show();
	ui->horizontalLayout_2->itemAt(1)->widget()->hide();
	ui->horizontalLayout_2->addWidget(field.data());
}


