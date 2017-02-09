#ifndef VHOD_H
#define VHOD_H

#include <QDialog>

namespace Ui {
class vhod;
}

class vhod : public QDialog
{
    Q_OBJECT

public:
    explicit vhod(QWidget *parent = 0);
    ~vhod();

private slots:
    void on_pushButton_clicked();
    void prov();
    void on_pushButton_2_clicked();

signals:
    void Dost(const QString &str);

private:
    Ui::vhod *ui;
};

#endif // VHOD_H
