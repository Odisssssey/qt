#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QTimer>
#include <time.h>
#include <QProgressBar>
#include <QCheckBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setEnabled(false);

    connect(ui->dom,SIGNAL(clicked()),this,SLOT(checd()));
    connect(ui->sax,SIGNAL(clicked()),this,SLOT(checd()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checd(){
    if ((ui->dom->isChecked()) || (ui->sax->isChecked())){
        ui->pushButton->setEnabled(true);
    }else{
        ui->pushButton->setEnabled(false);
    }

}

void MainWindow::on_pushButton_clicked()
{
    if(ui->dom->isChecked() && ui->sax->isChecked()){

    }else{
        if (ui->dom->isChecked()){
            checDom();
        }
        if (ui->sax->isChecked()){
            checSax();
        }
    }

}

void MainWindow::checSax(){
    QXmlStreamReader xmlReader;
    xmlReader.addData(ui->textBrowser->toPlainText());

    ui->treeWidget->clear();
    QStack<QTreeWidgetItem*> widgetStack;

    while (!xmlReader.atEnd()){
        if(xmlReader.isStartElement()){
           QStringList sl;
         //  QStringList tl;

           sl << xmlReader.name().toString();
          // st << xmlReader.name().toString();

          // tl << xmlReader.readElementText();
           QTreeWidgetItem *item = new QTreeWidgetItem(sl);

           if(widgetStack.count() == 0){
              ui->treeWidget->addTopLevelItem(item);
           }else{



               if ((sl[0] == "h1") || (sl[0] == "h2") || (sl[0] == "p") || (sl[0] == "string") || (sl[0] == "title") || (sl[0] == "a")){
                   QStringList tl;
                   tl << xmlReader.readElementText();
                   QStringList st;
                   st.append(sl[0]+" "+tl[0]);
                   QTreeWidgetItem *itm = new QTreeWidgetItem(st);
                   widgetStack.top()->addChild(itm);

               }else{

                widgetStack.top()->addChild(item);
               }

           }
           widgetStack.push(item);
        }
        if(xmlReader.isEndElement()){
            widgetStack.pop();
        }

        xmlReader.readNext();

    }
    ui->progressBar->setValue(100);
    QTimer::singleShot(500, this, SLOT(Time()));
}

void MainWindow::checDom(){
    QXmlStreamReader xmlReader;
    xmlReader.addData(ui->textBrowser->toPlainText());

    ui->treeWidget->clear();
    QStack<QTreeWidgetItem*> widgetStack;

    while (!xmlReader.atEnd()){
        if(xmlReader.isStartElement()){
           QStringList sl;
           sl << xmlReader.name().toString();
           QTreeWidgetItem *item = new QTreeWidgetItem(sl);
           if(widgetStack.count() == 0){
              ui->treeWidget->addTopLevelItem(item);
           }else{
               widgetStack.top()->addChild(item);
           }
           widgetStack.push(item);
        }
        if(xmlReader.isEndElement()){
            widgetStack.pop();
        }

        xmlReader.readNext();

    }
    ui->progressBar->setValue(100);
    QTimer::singleShot(500, this, SLOT(Time()));
}

void MainWindow::Time(){
    ui->progressBar->setValue(0);
}

void MainWindow::on_clean_clicked()
{
    ui->textBrowser->clear();
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
    ui->statusBar->showMessage("File is open");
    QString buffer = strem.readAll();

    ui->textBrowser->setText(buffer);

    ui->progressBar_2->setValue(100);
    QTimer::singleShot(500, this, SLOT(Tim()));

    QTimer *time = new QTimer(this);
    connect(time,SIGNAL(timeout()) ,this , SLOT(ActionTimer()));
    time->start(180000);



    mFile.flush();
    mFile.close();
}
void MainWindow::Tim(){
    ui->progressBar_2->setValue(0);
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
    stream << ui->textBrowser->toPlainText();
    mFile.close();

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
    stream << ui->textBrowser->toPlainText();

    mFile.close();
}

void MainWindow::on_saveAs_clicked()
{
    Dialog *wnd = new Dialog(this);
    wnd->show();

    connect(wnd,SIGNAL(FilePath(QString)),this,SLOT(saveAsFile(QString)));
}
void MainWindow::saveAsFile(const QString &filePath){
    QFile mFile(filePath);
    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"Error","Path not connect!");
        return;
    }
    QTextStream stream(&mFile);
    ui->statusBar->showMessage("Success full. Write to file.");
    stream << ui->textBrowser->toPlainText();

    mFile.close();
}

