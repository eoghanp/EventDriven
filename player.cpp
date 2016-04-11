#include "item.h"
#include "player.h"
#include <string>
#include <QDebug>


Player::Player(string description) {
    this->description = description;
}

Player::~Player(void)
{
    qDebug() << "PLAYER DESTROYED";
}



