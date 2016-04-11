#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <item.h>


class Player
{
public:
    Player(string description);
    virtual void addItem(item *item);
    string description;
    vector <item> playerItems;
    virtual ~Player();
};

#endif // PLAYER_H
