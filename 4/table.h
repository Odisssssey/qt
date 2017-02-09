#ifndef TABLE_H
#define TABLE_H

#include <QDialog>

namespace Ui {
class table;
}

class table : public QDialog
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = 0);
    ~table();

private slots:
    void on_save_clicked();

private:
    Ui::table *ui;
};

#endif // TABLE_H
