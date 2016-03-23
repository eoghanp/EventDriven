#include "map.h"
#include "ui_map.h"
#include "ui_ship.h"
#include "ship.h"

Map::Map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
}

Map::~Map()
{
    delete ui;
}

// Ship::ui shipUi = new Ship;






//sets name of room on map when entered and bold name of current room
void Map::discover(Room *rm)
{
    font.setBold(true);

    if(rm->shortDescription() =="Supply Room")
    {
        ui->supplyRoomLbl->setText(QString::fromStdString(rm->shortDescription()));
        ui->supplyRoomLbl->setFont(font);
    }
    else if (rm->shortDescription() =="Hallway")
    {
        ui->hallwayLbl->setText(QString::fromStdString(rm->shortDescription()));
        ui->hallwayLbl->setFont(font);
    }
    /*
    else if (rm->shortDescription() =="Weapons Room")
    {
        ui->weaponsRoomLbl->setText(QString::fromStdString(rm->shortDescription()));
        ui->weaponsRoomLbl->setFont(font);
    }
    else if (rm->shortDescription() =="Sleeping Quarters A")
    {
        ui->sleepingQuartersALbl->setText(QString::fromStdString(rm->shortDescription()));
        ui->sleepingQuartersALbl->setFont(font);
    }
    else if (rm->shortDescription() =="Engine Room")
    {
        ui->engineRoomLbl->setText(QString::fromStdString(rm->shortDescription()));
        ui->engineRoomLbl->setFont(font);
    }*/
}

//resets style of all room names
void Map::fontReset()
{
    font2.setBold(false);
    ui->supplyRoomLbl->setFont(font2);
    ui->hallwayLbl->setFont(font2);
    /*ui->computerLbl->setFont(font2);
    ui->aLbl->setFont(font2);
    ui->bLbl->setFont(font2);
    ui->cellLbl->setFont(font2);
    ui->bathroomLbl->setFont(font2);
    ui->basementLbl->setFont(font2);
    ui->officeLbl->setFont(font2);
    ui->tortureLbl->setFont(font2);*/
}
