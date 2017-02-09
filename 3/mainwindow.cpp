#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include "dialog.h"
#include <QApplication>
#include <QTimer>
#include <time.h>
#include "hi.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Ready to work!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_clicked()
{
    Dialog *wnd = new Dialog(this);
    wnd->show();

    connect(wnd,SIGNAL(FilePath(QString)),this,SLOT(ReadToFile(QString)));
}

void MainWindow::ReadToFile(const QString &filePath){
    QFile mFile(filePath);
    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(this,"Error","Path not connect!");
        ui->statusBar->showMessage("Error");
        return;
    }
    QTextStream strem(&mFile);

    QString buffer = strem.readAll();

    ui->textEdit->setText(buffer);

    QTimer::singleShot(500, this, SLOT(Hi()));

    QTimer *time = new QTimer(this);
    connect(time,SIGNAL(timeout()) ,this , SLOT(ActionTimer()));
    time->start(2000);



    mFile.flush();
    mFile.close();
}

void MainWindow::Hi(){
    hi *wndow = new hi(this);
    wndow->show();
}

void MainWindow::ActionTimer(){
    srand(time(NULL));

    QFile mFile(".//text.txt");
    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"Error","Path not connect!");
        return;
    }
    QTextStream stream(&mFile);
    ui->statusBar->showMessage("Auto save.");
    stream << ui->textEdit->toPlainText();
    mFile.close();

}

void MainWindow::on_clean_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_save_clicked()
{
    QFile mFile(".//text.txt");
    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"Error","Path not connect!");
        return;
    }
    QTextStream stream(&mFile);
    ui->statusBar->showMessage("Success full. Write to file.");
    stream << ui->textEdit->toPlainText();

    mFile.close();
}
