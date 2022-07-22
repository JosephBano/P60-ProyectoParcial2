#include "salaui.h"
#include "ui_salaui.h"
#include "principal.h"
#include "facturaui.h"
SalaUI::SalaUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SalaUI)
{
    ui->setupUi(this);
}

SalaUI::~SalaUI()
{
    delete ui;
}


void SalaUI::on_btnCancelar_released()
{
   close();
}

void SalaUI::on_btnComprar_released()
{

}

void SalaUI::on_pushButton_released()
{
    Distribuidor  *ventana = new Distribuidor;
    ventana->show();
}
