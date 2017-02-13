#include "reserve.h"
#include "ui_reserve.h"

Reserve::Reserve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reserve)
{
    ui->setupUi(this);
}

Reserve::~Reserve()
{
    delete ui;
}
