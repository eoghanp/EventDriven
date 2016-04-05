#include "item.h"
#include "player.h"
#include <string>
#include <QDebug>

Player::Player(string description, int health) {
    this->description = description;
    this->health = health;
}
//adds item to playerItem vector list
void Player::addItem(item *item) {
    playerItems.push_back(*item);
}

//checks if item is in playerItems vector list
bool Player::checkItem(string check)
{
    unsigned int k =(0);
    while(k < playerItems.size())
    {
        if(playerItems[k].getItemName() == check)
        {
            playerItems.pop_back();
            qDebug() << "Number of items:" << hasItem();
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


