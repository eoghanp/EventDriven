#include "ship.h"
#include <QApplication>
#include "startmenu.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSound>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMediaPlaylist * playlist = new QMediaPlaylist();
    int i =0;
    while (i < 10){
        playlist->addMedia(QUrl("qrc:/sounds/backgroundMusic.mp3"));
        i++;}
    QMediaPlayer *backgroundMusic = new QMediaPlayer();
    backgroundMusic->setPlaylist(playlist);
    backgroundMusic->play();
    QIcon icon(":/images/mainMenuBackground.jpg");
    a.setWindowIcon(icon);
    startMenu startGame;
    startGame.show();

    return a.exec();
}
