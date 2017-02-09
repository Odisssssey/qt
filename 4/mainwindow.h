#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void tabl(const QString &Dost);
    void action();

    void on_actionReLog_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
