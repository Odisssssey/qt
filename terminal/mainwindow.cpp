#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "search.h"
#include "reserve.h"
#include "inform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_pressed()
{
    Inform *wndow = new Inform(this);
    wndow->show();
}

void MainWindow::on_pushButton_2_pressed()
{
    Reserve *wndow = new Reserve(this);
    wndow->show();
}

void MainWindow::on_pushButton_pressed()
{
    Search *wndow = new Search(this);
    wndow->show();
}
