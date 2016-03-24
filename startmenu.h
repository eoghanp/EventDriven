#ifndef STARTMENU_H
#define STARTMENU_H

#include <QWidget>
#include "ship.h"

namespace Ui {
class startMenu;
}

class startMenu : public QWidget
{
    Q_OBJECT

public:
    explicit startMenu(QWidget *parent = 0);
    ~startMenu();
    //Ship *game;

private slots:
    void on_playBtn_clicked();

    void on_quitBtn_clicked();

private:
    Ui::startMenu *ui;
};

#endif // STARTMENU_H
