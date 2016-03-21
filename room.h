#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <map>
#include "item.h"
using namespace std;

class Room
{
public:
    Room(string description);
    string descrption;
    void setExits(Room *north, Room *east, Room *south, Room *west);
    Room *nextRoom(string direction);
    string shortDescription();
    vector <item> itemsInRoom;
    void addItem(item *roomItem);
    vector<item> displayItemsInRoom();
private:
    map<string, Room*> exits;


};



#endif // ROOM_H
