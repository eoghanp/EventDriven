#include "ship.h"
#include "ui_ship.h"
#include "room.h"
#include <QDebug>
#include <string>
#include <QPixmap>
#include <QIcon>
using namespace std;

Ship::Ship(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ship)
{
    ui->setupUi(this);
}

Ship::~Ship()
{
    delete ui;
}


void Ship::play()
{
    createMap();
    createRooms();
}

void Ship::createMap()
{
    scene = new QGraphicsScene(this);
    ui->mapOfShip->setScene(scene);
    scene->setBackgroundBrush(Qt::black);
}

void Ship::createRooms()
{
    Room *a = new Room("Supply Room"); //start area
    a->addItem(new item("Oxygen Tank"));
    Room *b = new Room("Hallway");
    Room *c = new Room("Sleeping Quarters A");
    Room *d = new Room("Sleeping Quarters B");
    d->addItem(new item("Red Key"));
    Room *e = new Room("Weapons Room");
    e->addItem(new item("Crow Bar"));
    Room *f = new Room("Engine Room");
    Room *g = new Room("Coal Room");
    e->addItem(new item("Shovel"));
    Room *h = new Room("Upstairs Hallway");
    Room *i = new Room("Kitchen");
    Room *j = new Room("Captains Quarters");
    j->addItem(new item("Handgun"));
    Room *k = new Room("Sun Deck");

    currentRoom = a;
    ui->tempText->setText(QString::fromStdString(currentRoom->shortDescription()));
    showAvailableExits();
    populateItemList();
    getDescriptionOfRoom();
    //(N, E, S,W)
    a->setExits(NULL, b, NULL, NULL);
    b->setExits(e, f, c, a);
    c->setExits(b, d, NULL, NULL);
    d->setExits(NULL, NULL, NULL, c);
    e->setExits(NULL, NULL, b, NULL);
    f->setExits(h, g, NULL, b);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, i, f, NULL);
    i->setExits(NULL, j, k, h);
    j->setExits(NULL, NULL, NULL, i);
    k->setExits(i, NULL, NULL, NULL);

    qDebug() << "Room created";
}

//sets current room to new room
//various function calls
void Ship::goToRoom(string dir)
{
    Room* nextRoom = currentRoom->nextRoom(dir);
    currentRoom = nextRoom;
    qDebug() << "Current room is " << currentRoom;
    ui->tempText->setText(QString::fromStdString(currentRoom->shortDescription()));
    showAvailableExits();
    populateItemList();
    getDescriptionOfRoom();
   // ui->itemList->setText(itemsInRoom);
    //ui->itemList->setText("Contains items in room");
    //ui->itemList->clear();
    //disImage();
    //roomDescription();
    //maap->discover(currentRoom);
    //ui->itemsComboBox->clear();
}

void Ship::getDescriptionOfRoom()
{
    ui->descriptionText->clear();
    if(currentRoom->shortDescription() == "Supply Room"){
      QFile inputFile(":/text/1_OldSupplyRoom.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
        QTextStream in(&inputFile);
            while (!in.atEnd() )
            {
                QString line = in.readLine();
                ui->descriptionText->append(line);
            }
        inputFile.close();
        }
    }
    else if(currentRoom->shortDescription() == "Hallway"){
      QFile inputFile(":/text/2_Hallway.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
        QTextStream in(&inputFile);
            while (!in.atEnd() )
            {
                QString line = in.readLine();
                ui->descriptionText->append(line);
            }
        inputFile.close();
        }
    }
    else if(currentRoom->shortDescription() == "Sleeping Quarters A"){
      QFile inputFile(":/text/3_SleepingQuartersA.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
        QTextStream in(&inputFile);
            while (!in.atEnd() )
            {
                QString line = in.readLine();
                ui->descriptionText->append(line);
            }
        inputFile.close();
        }
    }
    else if(currentRoom->shortDescription() == "Sleeping Quarters B"){
      QFile inputFile(":/text/4_SleepingQuartersB.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
        QTextStream in(&inputFile);
            while (!in.atEnd() )
            {
                QString line = in.readLine();
                ui->descriptionText->append(line);
            }
        inputFile.close();
        }
    }
    else if(currentRoom->shortDescription() == "Weapons Room"){
      QFile inputFile(":/text/5_WeaponsRoom.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
        QTextStream in(&inputFile);
            while (!in.atEnd() )
            {
                QString line = in.readLine();
                ui->descriptionText->append(line);
            }
        inputFile.close();
        }
    }
    else if(currentRoom->shortDescription() == "Engine Room"){
      QFile inputFile(":/text/6_EngineRoom.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
        QTextStream in(&inputFile);
            while (!in.atEnd() )
            {
                QString line = in.readLine();
                ui->descriptionText->append(line);
            }
        inputFile.close();
        }
    }
}

void Ship::on_quitButton_clicked()
{
    qApp->quit();
}


void Ship::on_eastButton_clicked()
{
    goToRoom("east");
}

void Ship::on_northButton_clicked()
{
    goToRoom("north");
}

void Ship::on_westButton_clicked()
{
    goToRoom("west");
}

void Ship::on_southButton_clicked()
{
    goToRoom("south");
}

/*void Ship::on_backpackButton_clicked()
{
    bag->show();
    bag->raise();
    bag->activateWindow();
    bag->setFocus();
}*/

void Ship::showAvailableExits()
{
    if (currentRoom->shortDescription() == "Supply Room"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Hallway"){
        ui->northButton->setEnabled(true);
        ui->northButton->setText("GO NORTH");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(true);
        ui->southButton->setText("GO SOUTH");
    }
    else if (currentRoom->shortDescription() == "Sleeping Quarters A"){
        ui->northButton->setEnabled(true);
        ui->northButton->setText("GO NORTH");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Sleeping Quarters B"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("NO EXIT");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Weapons Room"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(true);
        ui->southButton->setText("GO SOUTH");
    }
    else if (currentRoom->shortDescription() == "Engine Room"){
        ui->northButton->setEnabled(true);
        ui->northButton->setText("GO NORTH");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Coal Room"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("NO EXIT");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Upstairs Hallway"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(true);
        ui->southButton->setText("GO SOUTH");
    }
    else if (currentRoom->shortDescription() == "Kitchen"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(true);
        ui->southButton->setText("GO SOUTH");
    }
    else if (currentRoom->shortDescription() == "Captains Quarters"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("NO EXIT");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Sun Deck"){
        ui->northButton->setEnabled(true);
        ui->northButton->setText("GO NORTH");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("NO EXIT");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
}

void Ship::populateItemList(){
    ui->itemList->clear();
    itemsInCurrentRoom = currentRoom->displayItemsInRoom();
    unsigned int i = 0;
    while( i<itemsInCurrentRoom.size()){
        ui->itemList->addItem(QString::fromStdString(itemsInCurrentRoom[i].getItemName()));
        i++;
    }
}


