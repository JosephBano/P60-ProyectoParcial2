#include "facturaui.h"
#include "ui_facturaui.h"

FacturaUI::FacturaUI(QWidget *parent) :
    QWidget(parent),
    ui(new  Ui::FacturaUI)
{
    ui->setupUi(this);
}

FacturaUI::~FacturaUI()
{
    delete ui;
}
