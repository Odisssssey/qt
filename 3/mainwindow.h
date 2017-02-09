#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>

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

    void on_open_clicked();
    void ReadToFile(const QString& filePath);

    void on_clean_clicked();

    void on_save_clicked();

    void ActionTimer();

    void Hi();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
