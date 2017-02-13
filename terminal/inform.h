#ifndef INFORM_H
#define INFORM_H

#include <QDialog>

namespace Ui {
class Inform;
}

class Inform : public QDialog
{
    Q_OBJECT

public:
    explicit Inform(QWidget *parent = 0);
    ~Inform();

private:
    Ui::Inform *ui;
};

#endif // INFORM_H
