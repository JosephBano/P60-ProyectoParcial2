#include "salaui.h"
#include "ui_salaui.h"
#include "principal.h"

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

/*void SalaUI::dibujar()
{
    painter.drawLine(x+25,y+450,x+475,y+450);
}
*/

void SalaUI::on_pushButton_clicked()
{

}

void SalaUI::on_btnCancelar_released()
{
   close();
}
