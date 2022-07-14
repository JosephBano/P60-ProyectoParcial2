#ifndef SALAUI_H
#define SALAUI_H

#include <QWidget>
#include <QPainter>
#include <distribuidor.h>

namespace Ui {
class SalaUI;
}

class SalaUI : public QWidget
{
    Q_OBJECT

public:
    explicit SalaUI(QWidget *parent = nullptr);
    ~SalaUI();

private slots:

    void on_btnCancelar_released();

    void on_btnComprar_released();

    void on_pushButton_released();

private:
    Ui::SalaUI *ui;
    void dibujar();
};

#endif // SALAUI_H
