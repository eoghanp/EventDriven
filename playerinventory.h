#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H
#include "player.h"
#include <string>
#include <item.h>

class playerInventory : public Player
{
public:
    playerInventory(string description);
    //void addItem(item *item);
    bool checkItem(string check);
    int hasItem();

    //string description;
};

#endif // PLAYERINVENTORY_H
