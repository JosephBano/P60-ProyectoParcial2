#include "salaui.h"
#include "ui_salaui.h"

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
