#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <QFile>
#include <vector>

using namespace std;

class item
{
friend void getItemName();

public:
    item(string name);
    string getItemName();
    ~item();
private:
    string details;
};

#endif // ITEM_H
