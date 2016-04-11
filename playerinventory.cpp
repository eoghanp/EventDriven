#include "playerinventory.h"

playerInventory::playerInventory(string description):Player(description)
{
  this->description = description;
}

//adds item to playerItem vector list
void Player::addItem(item *item) {
    playerItems.push_back(*item);
}

//checks if item is in playerItems vector list
bool playerInventory::checkItem(string check)
{
    unsigned int k =(0);
    while(k < playerItems.size())
    {
        if(playerItems[k].getItemName() == check)
        {
            playerItems.pop_back();
            return true;
        }
        k++;
    }
}

//returns number of items in characterItems vector list
int playerInventory::hasItem()
{
    return playerItems.size();

}
