#ifndef DISTRIBUIDOR_H
#define DISTRIBUIDOR_H

#include <QDialog>
#include <QAbstractButton>
#include <facturaui.h>

namespace Ui {
class Distribuidor;
}

class Distribuidor : public QDialog
{
    Q_OBJECT

public:
    explicit Distribuidor(QWidget *parent = nullptr);
    ~Distribuidor();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Distribuidor *ui;
};

#endif // DISTRIBUIDOR_H
