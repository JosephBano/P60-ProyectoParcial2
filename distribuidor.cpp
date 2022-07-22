#include "distribuidor.h"
#include "ui_distribuidor.h"

Distribuidor::Distribuidor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Distribuidor)
{
    ui->setupUi(this);
}

Distribuidor::~Distribuidor()
{
    delete ui;
}

void Distribuidor::on_buttonBox_clicked(QAbstractButton *button)
{
     FacturaUI *factura = new FacturaUI;
    factura->show();
}
