#include "startmenu.h"
#include "ui_startmenu.h"
#include "ship.h"
#include "ui_ship.h"

startMenu::startMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startMenu)
{
    ui->setupUi(this);
}

startMenu::~startMenu()
{
    delete ui;
}

void startMenu::on_playBtn_clicked()
{
    Ship* game = new Ship();
    game->show();
    game->play();
    this->destroy();
}

void startMenu::on_quitBtn_clicked()
{
    qApp->quit();
}
