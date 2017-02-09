#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "vhod.h"
#include <QTableWidget>
#include <QToolBar>
#include <QtWidgets>
#include <QMenuBar>
#include <QAction>
#include "table.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    vhod *wndow = new vhod(this);
    wndow->show();

    connect(wndow,SIGNAL(Dost(QString)),this,SLOT(tabl(QString)));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::tabl(const QString &dost){


    if(dost == "admin"){
        ui->tableWidget->setRowCount(4);
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "a" << "b" << "c" << "d");
       // QToolBar *file = addAction(); ;->addMenu("File");
        QMenu *file = menuBar()->addMenu("Панель админа");
        QAction *newFile = new QAction(tr("Изменить доступ"),this);
        file->addAction(newFile);
        connect(newFile,SIGNAL(triggered()),this,SLOT(action()));
    }
    if(dost == "user"){
        ui->tableWidget->setRowCount(3);
        ui->tableWidget->setColumnCount(3);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "a" << "b" << "c");
    }

    int count = 1;
    for(int i=0 ; i < ui->tableWidget->rowCount(); i++){
        for(int j=0; j < ui->tableWidget->columnCount(); j++){
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(count));

            ui->tableWidget->setItem(i,j, itm);
            itm->setBackgroundColor(Qt::gray);
            count++;
        }
    }

}

void MainWindow::action(){
    table *wndow = new table(this);
    wndow->show();
}


void MainWindow::on_actionReLog_triggered()
{
    ui->tableWidget->clear();
    vhod *wndow = new vhod(this);
    wndow->show();

    connect(wndow,SIGNAL(Dost(QString)),this,SLOT(tabl(QString)));
}
