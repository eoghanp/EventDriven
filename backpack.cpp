#include "backpack.h"
#include "ui_backpack.h"
#include "ship.h"

Backpack::Backpack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Backpack)
{
    ui->setupUi(this);
}

Backpack::~Backpack()
{
    delete ui;
}
