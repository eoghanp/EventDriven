#include "gamecomplete.h"
#include "ui_gamecomplete.h"

gameComplete::gameComplete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameComplete)
{
    ui->setupUi(this);
}

gameComplete::~gameComplete()
{
    delete ui;
}

void gameComplete::on_restartGameBtn_clicked()
{
    Ship* restartGame = new Ship();
    restartGame->show();
    restartGame->play();
    this->destroy();
}

void gameComplete::on_backMainMenuBtn_clicked()
{
    startMenu *menu = new startMenu();
    menu->show();
    this->destroy();
}
