#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString str = "http://university.netology.ru/u/tarutin/9/VkVhod.php";
    ui->webView_2->load(QUrl(str));
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::slotEnter);

    connect(ui->webView, &QWebView::linkClicked, this, &MainWindow::slotLinkClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotEnter()
{
    // Загружаем страницу по заданном URL в поле lineEdit
    QString gogl = "https://www.google.ru/webhp?sourceid=chrome-instant&ion=1&espv=2&ie=UTF-8#q=" + ui->lineEdit->text();
    ui->webView->load(QUrl(gogl));
}

void MainWindow::slotLinkClicked(QUrl url)
{
    // При клике по ссылке помещаем адрес в поле lineEdit
    ui->lineEdit->setText(url.toString());
    ui->webView->load(url);     // Загружаем страницу по этой ссылке

}

