#include "item.h"


item::item(string name)
{
    details = name;
}

string item::getItemName(){
    return details;
}


