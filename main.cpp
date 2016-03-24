#include "ship.h"
#include <QApplication>
#include <QIcon>
#include "startmenu.h"
#include <QMediaPlayer>
#include <QSound>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMediaPlayer *backgroundMusic = new QMediaPlayer();
    backgroundMusic->setMedia(QUrl("qrc:/sounds/backgroundMusic.mp3"));
    backgroundMusic->play();
    QIcon icon(":/images/mainMenuBackground.jpg");
    a.setWindowIcon(icon);
    startMenu startGame;
    startGame.show();

    return a.exec();
}
