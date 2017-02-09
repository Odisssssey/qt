#include "table.h"
#include "ui_table.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

table::table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);

    QString filePath = "C:\\Qt\\prog\\lab4\\MainLab\\test.txt";

    QFile mFile(filePath);
    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(this,"Error","ну сам уж думай");
    }
    QTextStream strem(&mFile);

    QString buffer = strem.readAll();

    ui->textEdit->setText(buffer);

    QTextStream stream(&mFile);
    stream << ui->textEdit->toPlainText();

    mFile.close();
}

table::~table()
{
    delete ui;
}

void table::on_save_clicked()
{
    QString filePath = "C:\\Qt\\prog\\lab4\\MainLab\\test.txt";

    QFile mFile(filePath);
    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"Error","ну сам уж думай");
    }
    QTextStream stream(&mFile);
    stream << ui->textEdit->toPlainText();

    mFile.close();
}
