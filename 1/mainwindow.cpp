#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCharFormat>
#include "dialog.h"

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

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->calendarWidget->update();
    ui->calendarWidget->setFirstDayOfWeek(Qt::DayOfWeek(index+1));

    QTextCharFormat format;

    format.setForeground(qvariant_cast<QColor>("red"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(6), format);
    format.setForeground(qvariant_cast<QColor>("red"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(7), format);
    format.setForeground(qvariant_cast<QColor>("blak"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(5), format);
    format.setForeground(qvariant_cast<QColor>("blak"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(4), format);
    format.setForeground(qvariant_cast<QColor>("blak"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(3), format);
    format.setForeground(qvariant_cast<QColor>("blak"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(2), format);
    format.setForeground(qvariant_cast<QColor>("blak"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(1), format);

    format.setForeground(qvariant_cast<QColor>("green"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(index+1), format);

}

void MainWindow::on_action_triggered()
{
    Dialog *wndow = new Dialog(this);
    wndow->show();
}
