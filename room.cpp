#include "Room.h"
#include <string>
#include "item.h"
#include "ship.h"
#include <QDebug>

using namespace std;

Room::Room(string description)
{
    this->descrption = description;
    listOfRooms.push_back(description);
}

//returns room name
string Room::shortDescription()
{
    return this->descrption;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west)
{
    if (north != NULL)
        exits["north"] = north;
    if(east != NULL)
        exits["east"] = east;
    if(south != NULL)
        exits["south"] = south;
    if(west != NULL)
        exits["west"] = west;
}


//returns a room in given direction
Room* Room::nextRoom(string direction)
{
    map<string, Room*>::iterator next = exits.find(direction);
    if(next== exits.end())
        return NULL;
    return next->second;
}


//adds item to room
void Room::addItem(item *roomItem) {
    itemsInRoom.push_back(*roomItem);
}

vector <item> Room::displayItemsInRoom(){
    return itemsInRoom;
}

//remove item from room
void Room::removeItemFromRoom(int location){
    itemsInRoom.erase(itemsInRoom.begin() + location);
}


