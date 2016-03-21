#include "ship.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ship game;
    game.play();
    game.show();

    return a.exec();
}
