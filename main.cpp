#include "ship.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ship game;
    Map map;
    game.play();
    game.show();
    //map.show();

    return a.exec();
}
