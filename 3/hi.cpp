#include "hi.h"
#include "ui_hi.h"

hi::hi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hi)
{
    ui->setupUi(this);
}

hi::~hi()
{
    delete ui;
}
