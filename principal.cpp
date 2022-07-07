#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    on_info1_inputRejected();
}

Principal::~Principal()
{
    delete ui;
}


/*void Principal::on_info1_textEdited(const QString &arg1)
{
    ui->info1->setText("Los Minions [120]");

}*/

void Principal::on_info1_inputRejected()
{
    ui->info1->setText("Pan");
}
