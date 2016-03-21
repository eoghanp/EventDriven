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
    ui->textEdit->setText("You have woke up in a dark room with a small window. \nThere is a small window and a steel door"
                          " in front of you. \nThe room is empty and cold.");
}

void Ship::createMap()
{
    scene = new QGraphicsScene(this);
    ui->mapOfShip->setScene(scene);
    scene->setBackgroundBrush(Qt::black);
    QPixmap pix(":/rucksack.png");
    QIcon ButtonIcon(pix);
    ui->backpackButton->setIcon(ButtonIcon);
    ui->backpackButton->setIconSize(pix.rect().size());
}

void Ship::createRooms()
{
    Room *a = new Room("Room one"); //start area
    a->addItem(new item("Oxygen Tank"));
    Room *b = new Room("Room two");
    Room *c = new Room("Room three");
    Room *d = new Room("Room four");
    d->addItem(new item("Red Key"));
    Room *e = new Room("Room five");
    e->addItem(new item("Crow Bar"));
    Room *f = new Room("Room six");
    Room *g = new Room("Room seven");
    Room *h = new Room("Room eight");
    Room *i = new Room("Room nine");
    Room *j = new Room("Room ten");

    currentRoom = a;
    ui->tempText->setText(QString::fromStdString(currentRoom->shortDescription()));
    showAvailableExits();
    populateItemList();
    //(N, E, S,W)
    a->setExits(NULL, b, NULL, NULL);
    b->setExits(d, f, c, a);
    c->setExits(b, e, NULL, NULL);
    d->setExits(NULL, NULL, b, NULL);
    e->setExits(NULL, NULL, NULL, c);
    f->setExits(g, NULL, NULL, b);
    g->setExits(NULL, h, f, NULL);
    h->setExits(NULL, i, j, g);
    i->setExits(NULL, NULL, NULL, h);
    j->setExits(h, NULL, NULL, NULL);

    qDebug() << "Room created";
}

//sets current room to new room
//various function calls
void Ship::goToRoom(string dir)
{

    //ui->textEdit->setText("");
    //maap->fontReset();
    Room* nextRoom = currentRoom->nextRoom(dir);
    currentRoom = nextRoom;
    qDebug() << "Current room is " << currentRoom;
    ui->tempText->setText(QString::fromStdString(currentRoom->shortDescription()));
    showAvailableExits();
    populateItemList();
   // ui->itemList->setText(itemsInRoom);
    //ui->itemList->setText("Contains items in room");
    //ui->itemList->clear();
    //disImage();
    //roomDescription();
    //maap->discover(currentRoom);
    //ui->itemsComboBox->clear();





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
    if (currentRoom->shortDescription() == "Room one"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Room two"){
        ui->northButton->setEnabled(true);
        ui->northButton->setText("GO NORTH");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(true);
        ui->southButton->setText("GO SOUTH");
    }
    else if (currentRoom->shortDescription() == "Room three"){
        ui->northButton->setEnabled(true);
        ui->northButton->setText("GO NORTH");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Room four"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(true);
        ui->southButton->setText("GO SOUTH");
    }
    else if (currentRoom->shortDescription() == "Room five"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("NO EXIT");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Room six"){
        ui->northButton->setEnabled(true);
        ui->northButton->setText("GO NORTH");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("NO EXIT");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Room seven"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(true);
        ui->southButton->setText("GO SOUTH");
    }
    else if (currentRoom->shortDescription() == "Room eight"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(true);
        ui->southButton->setText("GO SOUTH");
    }
    else if (currentRoom->shortDescription() == "Room nine"){
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("NO EXIT");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
    }
    else if (currentRoom->shortDescription() == "Room ten"){
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


