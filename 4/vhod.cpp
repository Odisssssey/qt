#include "vhod.h"
#include "ui_vhod.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>

#include <QStringList>

vhod::vhod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vhod)
{
    ui->setupUi(this);
}

vhod::~vhod()
{
    delete ui;
}

void vhod::on_pushButton_clicked()
{
    vhod::prov();
}

void vhod::prov(){
    QString filePath = "C:\\Qt\\prog\\lab4\\MainLab\\test.txt";

    QFile mFile(filePath);
    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(this,"Error","ну сам уж думай");
    }
    QTextStream strem(&mFile);

       while (!strem.atEnd())
       {
          QString line = strem.readLine();
          QStringList list = QString(line).split(";");

          if((ui->login->text() == list[0]) && (ui->pass->text() == list[1])){
              //QMessageBox::information(this,"Error",list[0]);
              emit Dost(ui->login->text());
              close();
          }


       }

}

void vhod::on_pushButton_2_clicked()
{
    QString filePath = "C:\\Qt\\prog\\lab4\\MainLab\\test.txt";

    QFile mFile(filePath);
    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(this,"Error","ну сам уж думай");
    }
    QTextStream strem(&mFile);

       while (!strem.atEnd())
       {
          QString line = strem.readLine();
          QStringList list = QString(line).split(";");

          if(ui->login->text() == list[0]){
              QMessageBox::information(this,"jast do it",list[2]);
          }


       }
}
