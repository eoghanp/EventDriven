#ifndef SHIP_H
#define SHIP_H

#include <QMainWindow>
#include <string>
#include <QGraphicsScene>
#include <QtGui>
#include <QtCore>
#include <QFont>
#include "room.h"
#include "player.h"
#include "startmenu.h"
#include "gamecomplete.h"
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
    bool oxygenTankUsed;
    void createRooms();
    void goToRoom(string dir);
    void showAvailableExits();
    void updateText();
    vector <item> itemsInCurrentRoom;
    void resetTextFormat();
    QFont fontItalic;
    QFont fontBold;
    vector<item> inventory;
    void createPlayer();
    Player *mainPlayer;
    QString tempQSItem;
    string currItem;
    void hideInventoryItems();
    Ui::Ship *ui;
protected:
    void getDescriptionOfRoom();
private:
    Room *currentRoom;

    bool crowbarUsed;
    bool redKeyUsed;
    bool silverKeyUsed;
    bool goldKeyUsed;
    bool handgunUsed;

    QFont font;
    QGraphicsScene *scene;
    void populateItemList();
private slots:
    void on_quitButton_clicked();
    void on_eastButton_clicked();
    void on_northButton_clicked();
    void on_westButton_clicked();
    void on_southButton_clicked();
    void on_takeItemButton_clicked();
    void on_oxygenTankbtn_clicked();
    void on_crowbarBtn_clicked();
    void on_redKeyBtn_clicked();
    void on_shovelBtn_clicked();
    void on_silverKeyBtn_clicked();
    void on_goldKeyBtn_clicked();
    void on_handgunBtn_clicked();
};

#endif // SHIP_H
