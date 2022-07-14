#ifndef FACTURAUI_H
#define FACTURAUI_H

#include <QWidget>

namespace Ui {
class FacturaUI;
}

class FacturaUI : public QWidget
{
    Q_OBJECT

public:
    explicit FacturaUI(QWidget *parent = nullptr);
    ~FacturaUI();

private:
    Ui::FacturaUI *ui;
};

#endif // FACTURAUI_H
