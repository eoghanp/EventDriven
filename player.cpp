#include "item.h"
#include "player.h"
#include <string>

Player::Player(string description) {
    this->description = description;
}
//adds item to playerItem vector list
void Player::addItem(item *item) {
    playerItems.push_back(*item);
}

//checks if item is in playerItems vector list
bool Player::checkItem(string check)
{
    int k =(0);
    while(k < playerItems.size())
    {
        if(playerItems[k].getItemName() == check)
        {
            return true;
        }
        k++;
    }
}

//returns number of items in characterItems vector list
int Player::hasItem()
{
    return playerItems.size();

}
