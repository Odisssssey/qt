#ifndef HI_H
#define HI_H

#include <QDialog>

namespace Ui {
class hi;
}

class hi : public QDialog
{
    Q_OBJECT

public:
    explicit hi(QWidget *parent = 0);
    ~hi();

private:
    Ui::hi *ui;
};

#endif // HI_H
