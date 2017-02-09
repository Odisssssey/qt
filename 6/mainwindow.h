#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKitWidgets/QWebView>
#include <Qurl>

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

    void slotEnter();

    void slotLinkClicked(QUrl url);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
