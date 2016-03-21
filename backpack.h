#ifndef BACKPACK_H
#define BACKPACK_H
#include "ship.h"
#include <QWidget>

namespace Ui {
class Backpack;
}

class Backpack : public QWidget
{
    Q_OBJECT

public:
    explicit Backpack(QWidget *parent = 0);
    ~Backpack();

private:
    Ui::Backpack *ui;
};

#endif // BACKPACK_H
