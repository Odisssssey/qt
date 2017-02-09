#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QSpinBox>
#include <QComboBox>
#include <QString>

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

void MainWindow::on_save_clicked()
{
    QFile mFile(".//text.txt");
    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"Error","Path not connect!");
        //ui->statusBar->showMessage("Error");
        return;
    }
    //ui->statusBar->showMessage("Success full. Write to file.");
    QTextStream stream(&mFile);

    stream << ui->spinBox->value();
    stream << QString(" лет\n");
    stream << ui->comboBox->currentText();
    stream << QString(" пол\n");
    stream << ui->textEdit->toPlainText();

    mFile.close();

}
