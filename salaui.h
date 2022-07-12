#ifndef SALAUI_H
#define SALAUI_H

#include <QWidget>

namespace Ui {
class SalaUI;
}

class SalaUI : public QWidget
{
    Q_OBJECT

public:
    explicit SalaUI(QWidget *parent = nullptr);
    ~SalaUI();

private:
    Ui::SalaUI *ui;
};

#endif // SALAUI_H
