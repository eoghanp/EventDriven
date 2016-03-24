#ifndef GAMECOMPLETE_H
#define GAMECOMPLETE_H

#include <QWidget>
#include "ship.h"
#include "startmenu.h"

namespace Ui {
class gameComplete;
}

class gameComplete : public QWidget
{
    Q_OBJECT

public:
    explicit gameComplete(QWidget *parent = 0);
    ~gameComplete();

private slots:
    void on_restartGameBtn_clicked();

    void on_backMainMenuBtn_clicked();

private:
    Ui::gameComplete *ui;
};

#endif // GAMECOMPLETE_H
