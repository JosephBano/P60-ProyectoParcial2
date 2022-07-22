#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_info1_textEdited(const QString &arg1)
{


}

void Principal::on_info1_inputRejected()
{

}

void Principal::on_comprar1_clicked()
{
    SalaUI * ventana = new SalaUI;
    ventana->show();
}

void Principal::on_comprar2_clicked()
{
    SalaUI *ventana = new SalaUI;
    ventana->show();
}

void Principal::on_comprar3_clicked()
{
    SalaUI *ventana = new SalaUI;
    ventana->show();
}

void Principal::on_comprar4_clicked()
{
    SalaUI *ventana = new SalaUI;
    ventana->show();
}

void Principal::on_comprar5_clicked()
{
    SalaUI *ventana = new SalaUI;
    ventana->show();
}
