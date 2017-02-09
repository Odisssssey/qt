#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QXmlStreamReader>
#include <QTreeWidgetItem>
#include <QStack>
#include <QDebug>
#include <QPushButton>

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
    void on_pushButton_clicked();

    void ReadToFile(const QString& filePath);

    void saveAsFile(const QString &filePath);

    void ActionTimer();

    void checd();

    void checSax();

    void checDom();

    void Time();

    void Tim();

    void on_clean_clicked();

    void on_open_clicked();

    void on_save_clicked();

    void on_saveAs_clicked();




private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
