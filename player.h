#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <item.h>

class Player
{
public:
    Player(string description);
    void addItem(item *item);
    bool checkItem(string check);
    int hasItem();
    vector <item> playerItems;
    string description;
};

#endif // PLAYER_H
