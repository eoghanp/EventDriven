#include "item.h"
#include <QDebug>

item::item(string name)
{
    details = name;
}

item::~item(void)
{
    qDebug() << "ITEM DESTROYED";
}

string item::getItemName(){
    return details;
}


