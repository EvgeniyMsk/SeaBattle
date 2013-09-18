#include "tabOfInformation.h"
#include "ui_tabOfInformation.h"

TabOfInformation::TabOfInformation(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TabOfInformation)
{
	ui->setupUi(this);
	QString text = QString::fromLocal8Bit ("ЗДРАВСТВУЙ, УВАЖАЕМЫЙ ИГРОК!\nУстанови флот и в бой!\n");
	text += QString::fromLocal8Bit("Подсказка: для установки корабля ЛКМ нажмите на нужной клетке ");
	text += QString::fromLocal8Bit("и отпустите на той же или на другой клетке, где должен закончится корабль");
	text += QString::fromLocal8Bit("\nДля удаления корабля нажмите ПКМ на любой клетке, из тех, что он занимает.");
	ui->textBrowser->setText(text);
	this->setMaximumSize(sizeOfCube + 40, sizeOfCube + 40);
	this->setMinimumSize(sizeOfCube + 40, sizeOfCube + 40);
	connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(pushButtonReadyToFight()));
	connect(ui->toolButton_2, SIGNAL(clicked()), this, SIGNAL(needAutoSetting()));
	ui->label->setPixmap(QPixmap(":/pictures/aerocarrier.png"));
	ui->label_2->setPixmap(QPixmap(":/pictures/cruiser.png"));
	ui->label_3->setPixmap(QPixmap(":/pictures/destroyer.png"));
	ui->label_4->setPixmap(QPixmap(":/pictures/boat scout.png"));
}

TabOfInformation::~TabOfInformation()
{
	delete ui;
}

void TabOfInformation::changeCountOfShip(NameOfShips ship, int count)
{
	switch (ship){
	case AEROCARRIER:{
		ui->lcdNumber_4->display(ui->lcdNumber_4->value() + count);
		break;
	}
	case CRUISER:{
		ui->lcdNumber_3->display(ui->lcdNumber_3->value() + count);
		break;
	}
	case DESTROYER:{
		ui->lcdNumber_2->display(ui->lcdNumber_2->value() + count);
		break;
	}
	case BOAT_SCOUT:{
		ui->lcdNumber->display(ui->lcdNumber->value() + count);
		break;
	}
	}
}


void TabOfInformation::pushButtonReadyToFight()
{
	if (isReady()){
		emit fieldIsReady();
	}
}

bool TabOfInformation::isReady()
{
	return (ui->lcdNumber->value() == 0.0) && (ui->lcdNumber_2->value() == 0.0)
			&& (ui->lcdNumber_3->value() == 0.0) && (ui->lcdNumber_4->value() == 0.0);
}
