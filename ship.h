#ifndef SHIP_H
#define SHIP_H

#include <QMainWindow>
#include <string>
#include <QGraphicsScene>
#include "room.h"
#include "backpack.h"
using namespace std;

namespace Ui {
class Ship;
}

class Ship : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ship(QWidget *parent = 0);
    ~Ship();
    void play();
    void createMap();
    void createRooms();
    void goToRoom(string dir);
    void showAvailableExits();
    vector <item> itemsInCurrentRoom;
    //Backpack *bag;
protected:
    void getDescriptionOfRoom();
private:
    Room *currentRoom;
private slots:
    void on_quitButton_clicked();
    void on_eastButton_clicked();
    void on_northButton_clicked();
    void on_westButton_clicked();

    void on_southButton_clicked();

    //void on_backpackButton_clicked();

private:
    Ui::Ship *ui;
    QGraphicsScene *scene;
    void populateItemList();
    //QFile inputFile;
};

#endif // SHIP_H
