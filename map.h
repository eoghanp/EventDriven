#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include "Room.h"
#include <qfont.h>
#include <string>

namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = 0);
    ~Map();
    void discover(Room *rm);
    void fontReset();

signals:
  void  sendText(const QString & newText);

private:
    Ui::Map *ui;
    QFont font;
    QFont font2;
};

#endif // MAP_H
