#ifndef SALAUI_H
#define SALAUI_H

#include <QWidget>
#include <QPainter>

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
    void on_pushButton_clicked();

    void on_btnCancelar_released();

private:
    Ui::SalaUI *ui;
    void dibujar();
};

#endif // SALAUI_H
