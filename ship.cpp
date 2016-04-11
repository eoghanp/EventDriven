#include "ship.h"
#include "ui_ship.h"
#include "room.h"
#include <QDebug>
#include <string>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <QSound>
#include <QMediaPlayer>

using namespace std;

Ship::Ship(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ship)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    this->setWindowTitle("Lost At Sea");
}

Ship::~Ship()
{
    delete ui;
}


void Ship::play()
{
    createMap();
    createPlayer();
    hideInventoryItems();
    createRooms();
}

void Ship::createMap()
{
    scene = new QGraphicsScene(this);
    ui->mapOfShip->setScene(scene);
}

void Ship::createPlayer()
{
    mainPlayer = new playerInventory("Bob");
}

void Ship::hideInventoryItems(){
    ui->oxygenTankbtn->hide();
    oxygenTankUsed = false;
    ui->crowbarBtn->hide();
    crowbarUsed = false;
    ui->redKeyBtn->hide();
    redKeyUsed = false;
    ui->shovelBtn->hide();
    ui->silverKeyBtn->hide();
    silverKeyUsed = false;
    ui->goldKeyBtn->hide();
    goldKeyUsed = false;
    ui->handgunBtn->hide();
    handgunUsed = false;
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
    f->addItem(new item("Shovel"));
    Room *g = new Room("Coal Room");
    Room *h = new Room("Upstairs Hallway");
    h->addItem(new item("Gold Key"));
    Room *i = new Room("Kitchen");
    Room *j = new Room("Captains Quarters");
    j->addItem(new item("Handgun"));
    Room *k = new Room("Sun Deck");
    currentRoom = a;
    ui->roomNamelbl->setText(QString::fromStdString(currentRoom->shortDescription()));
    ui->itemsInRoomlbl->setText("Items in " + QString::fromStdString(currentRoom->shortDescription()));
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
}

//sets current room to new room
void Ship::goToRoom(string dir)
{
    Room* nextRoom = currentRoom->nextRoom(dir);
    currentRoom = nextRoom;
    ui->roomNamelbl->setText(QString::fromStdString(currentRoom->shortDescription()));
    ui->itemsInRoomlbl->setText("Items in " + QString::fromStdString(currentRoom->shortDescription()));
    showAvailableExits();
    populateItemList();
    getDescriptionOfRoom();
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
    else if(currentRoom->shortDescription() == "Coal Room"){
      QFile inputFile(":/text/7_CoalRoom.txt");
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
    else if(currentRoom->shortDescription() == "Upstairs Hallway"){
      QFile inputFile(":/text/8_UpstairsHallway.txt");
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
    else if(currentRoom->shortDescription() == "Kitchen"){
      QFile inputFile(":/text/9_Kitchen.txt");
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
    else if(currentRoom->shortDescription() == "Captains Quarters"){
      QFile inputFile(":/text/10_CaptainsQuarters.txt");
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
    startMenu *backToMenu = new startMenu();
    backToMenu->show();
    this->destroy();
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


void Ship::resetTextFormat(){
    QColor black = Qt::black;
    QString fontTemplate = tr("<font color='%1'>%2</font>");
    ui->supplyRoomLbl->setText(fontTemplate.arg(black.name(), "Supply Room"));
    ui->hallwayLbl->setText(fontTemplate.arg(black.name(), "Hallway"));
    ui->weaponsRoomLbl->setText(fontTemplate.arg(black.name(), "Weapons Room"));
    ui->sleepingQuartersALbl->setText(fontTemplate.arg(black.name(), "Sleeping Quarters A"));
    ui->sleepingQuartersBLbl->setText(fontTemplate.arg(black.name(), "Sleeping Quarters B"));
    ui->engineRoomLbl->setText(fontTemplate.arg(black.name(), "Engine Room"));
    ui->coalRoomLbl->setText(fontTemplate.arg(black.name(), "Coal Room"));
    ui->upstairsHallwayLbl->setText(fontTemplate.arg(black.name(), "Upstairs Hallway"));
    ui->kitchenLbl->setText(fontTemplate.arg(black.name(), "Kitchen"));
    ui->captainsQuartersLbl->setText(fontTemplate.arg(black.name(), "Captains Quarters"));
    ui->sundeckLbl->setText(fontTemplate.arg(black.name(), "Sundeck"));
}


void Ship::showAvailableExits()
{
   resetTextFormat();
   QColor yellow = Qt::white;
    QString fontTemplate = tr("<font color='%1'>%2</font>");
    fontItalic.setItalic(true);
    fontBold.setBold(true);
    if (currentRoom->shortDescription() == "Supply Room"){
        ui->supplyRoomLbl->setFont(fontItalic);
        ui->supplyRoomLbl->setText(fontTemplate.arg(yellow.name(), "Supply Room"));
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("GO EAST");
        if(oxygenTankUsed == true)
          ui->eastButton->setEnabled(true);
    }
    else if (currentRoom->shortDescription() == "Hallway"){
        ui->hallwayLbl->setFont(fontItalic);
        ui->hallwayLbl->setText(fontTemplate.arg(yellow.name(), "Hallway"));
        ui->northButton->setEnabled(true);
        ui->northButton->setText("GO NORTH");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("GO SOUTH");
        ui->hallwayLbl->setFont(font);
       if(crowbarUsed ==true)
         ui->southButton->setEnabled(true);
       if(redKeyUsed == true)
           ui->eastButton->setEnabled(true);
    }
    else if (currentRoom->shortDescription() == "Sleeping Quarters A"){
        ui->sleepingQuartersALbl->setText(fontTemplate.arg(yellow.name(), "Sleeping Quarters A"));
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
        ui->sleepingQuartersBLbl->setText(fontTemplate.arg(yellow.name(), "Sleeping Quarters B"));
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
        ui->weaponsRoomLbl->setText(fontTemplate.arg(yellow.name(), "Weapons Room"));
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(false);
        ui->westButton->setText("NO EXIT");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(true);
        ui->southButton->setText("GO SOUTH");
        if(silverKeyUsed == true)
            ui->northButton->setEnabled(true);
    }
    else if (currentRoom->shortDescription() == "Engine Room"){
        ui->engineRoomLbl->setText(fontTemplate.arg(yellow.name(), "Engine Room"));
        ui->northButton->setEnabled(false);
        ui->northButton->setText("GO NORTH");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(true);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("NO EXIT");
        if(silverKeyUsed== true)
            ui->northButton->setEnabled(true);
    }
    else if (currentRoom->shortDescription() == "Coal Room"){
        ui->coalRoomLbl->setText(fontTemplate.arg(yellow.name(), "Coal Room"));
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
        ui->upstairsHallwayLbl->setText(fontTemplate.arg(yellow.name(), "Upstairs Hallway"));
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
        ui->kitchenLbl->setText(fontTemplate.arg(yellow.name(), "Kitchen"));
        ui->northButton->setEnabled(false);
        ui->northButton->setText("NO EXIT");
        ui->westButton->setEnabled(true);
        ui->westButton->setText("GO WEST");
        ui->eastButton->setEnabled(false);
        ui->eastButton->setText("GO EAST");
        ui->southButton->setEnabled(false);
        ui->southButton->setText("GO SOUTH");
        if(goldKeyUsed == true)
            ui->eastButton->setEnabled(true);
        if(handgunUsed == true)
            ui->southButton->setEnabled(true);
    }
    else if (currentRoom->shortDescription() == "Captains Quarters"){
        ui->captainsQuartersLbl->setText(fontTemplate.arg(yellow.name(), "Captains Quarters"));
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
        gameComplete *completeScreen = new gameComplete();
        completeScreen->show();
        this->destroy();
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
    if(i == 0)
        ui->takeItemButton->setEnabled(false);
    else ui->takeItemButton->setEnabled(true);
}


void Ship::on_takeItemButton_clicked()
{
    QString selectedItem =  ui->itemList->currentText();
    //Converts QString to 8 bit representation and returns a pointer to data stored in QString
    currItem = selectedItem.toLocal8Bit().constData();
    mainPlayer->addItem(new item(currItem));
    //Removes item from room item vector
    int j;
    for(unsigned int i=0 ; i<itemsInCurrentRoom.size() ; i++){
        if(currItem == itemsInCurrentRoom[i].getItemName()){
            j = i ;
            currentRoom->removeItemFromRoom(j);
        }
    }
    itemsInCurrentRoom = currentRoom->displayItemsInRoom();
    //Takes item name from item drop down
    ui->itemList->clear();
    for(unsigned int i = 0; i<itemsInCurrentRoom.size(); i++){
        ui->itemList->addItem(QString::fromStdString(itemsInCurrentRoom[i].getItemName()));
    }
    if(itemsInCurrentRoom.size() == 0)
        ui->takeItemButton->setEnabled(false);
    showAvailableExits();

    //TODO: if object is used, remove from player list
    if(mainPlayer->checkItem("Oxygen Tank") == true){
        ui->oxygenTankbtn->show();
        ui->descriptionText->setText("You have picked up an oxygen tank. This will help you deal with the thin air. Click the tank icon to leave this room.");
    }
    else if(mainPlayer->checkItem("Crow Bar") == true){
        ui->crowbarBtn->show();
        ui->descriptionText->setText("You have picked up a crowbar. This could be useful to break open doors");}
    else if(mainPlayer->checkItem("Red Key") == true){
        ui->redKeyBtn->show();
        ui->descriptionText->setText("You have found a red key");}
    else if(mainPlayer->checkItem("Shovel") == true){
        ui->shovelBtn->show();
        ui->descriptionText->setText("You have picked up a shovel. This may be handy to use in rooms further on.");}
    else if(mainPlayer->checkItem("Silver Key") == true){
        ui->silverKeyBtn->show();
        ui->descriptionText->setText("You have picked up a silver key!");}
    else if(mainPlayer->checkItem("Gold Key") == true){
        ui->goldKeyBtn->show();
        ui->descriptionText->setText("You have found a gold key. This is a very fancy key!");}
    else if(mainPlayer->checkItem("Handgun") == true){
        ui->handgunBtn->show();
        ui->descriptionText->setText("You have found a handgun. Use wisely! You could try shooting open any door locks.");
        }
}

void Ship::on_oxygenTankbtn_clicked()
{
    ui->eastButton->setEnabled(true);
    ui->oxygenTankbtn->setEnabled(false);
    oxygenTankUsed = true;
    ui->descriptionText->setText("Door is open");
}

void Ship::on_crowbarBtn_clicked()
{
   if(currentRoom->shortDescription() == "Hallway"){
       ui->southButton->setEnabled(true);
       ui->crowbarBtn->setEnabled(false);
       crowbarUsed = true;
       ui->descriptionText->setText("You have cracked open the door with the crowbar");
   }
   else ui->descriptionText->setText("The crowbar is useless in this room");
}

void Ship::on_redKeyBtn_clicked()
{
    if(currentRoom->shortDescription() == "Hallway"){
        ui->eastButton->setEnabled(true);
        ui->redKeyBtn->setEnabled(false);
        redKeyUsed = true;
        ui->descriptionText->setText("The key fits! The door is open to the next room.");
    }
    else ui->descriptionText->setText("The red key is useless in this room");
}

void Ship::on_shovelBtn_clicked()
{
   if(currentRoom->shortDescription() == "Coal Room"){
        currentRoom->addItem(new item("Silver Key"));
        populateItemList();
        ui->shovelBtn->setEnabled(false);
        ui->descriptionText->setText("LOOK theres a key!");
   }
   else ui->descriptionText->setText("There is no need to use the shovel in this room");
}

void Ship::on_silverKeyBtn_clicked()
{
    if(currentRoom->shortDescription() == "Engine Room"){
        ui->northButton->setEnabled(true);
        ui->silverKeyBtn->setEnabled(false);
        silverKeyUsed = true;
        ui->descriptionText->setText("The key fits in this door. The next room is accessible");
    }
    else ui->descriptionText->setText("There is no door in this room that the siler key fits into");
}

void Ship::on_goldKeyBtn_clicked()
{
    if(currentRoom->shortDescription() == "Kitchen"){
        ui->eastButton->setEnabled(true);
        ui->goldKeyBtn->setEnabled(false);
        goldKeyUsed = true;
        ui->descriptionText->setText("You have opened a door with a label on the door saying 'Captains Quarters'");
    }
    else ui->descriptionText->setText("There is no door in this room that the gold key fits into");
}

void Ship::on_handgunBtn_clicked()
{
    if(currentRoom->shortDescription() == "Kitchen"){
        ui->southButton->setEnabled(true);
        ui->handgunBtn->setEnabled(false);
        handgunUsed = true;
        QMediaPlayer *shot = new QMediaPlayer();
        shot->setMedia(QUrl("qrc:/sounds/gunshot.mp3"));
        shot->play();
        ui->descriptionText->setText("BOOM! You have shot the lock right off! NOW RUN!!");
    }
    else ui->descriptionText->setText("Why would you waste a bullet in this room?");
}
