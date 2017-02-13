#include "inform.h"
#include "ui_inform.h"

Inform::Inform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inform)
{
    ui->setupUi(this);
}

Inform::~Inform()
{
    delete ui;
}
