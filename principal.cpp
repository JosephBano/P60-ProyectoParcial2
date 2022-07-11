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


void Principal::on_info1_textEdited(const QString &arg1)
{


}

void Principal::on_info1_inputRejected()
{

}
