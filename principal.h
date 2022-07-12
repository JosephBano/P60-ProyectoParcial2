#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <salaui.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_info1_textEdited(const QString &arg1);

    void on_info1_inputRejected();

    void on_comprar1_clicked();

    void on_comprar2_clicked();

    void on_comprar3_clicked();

    void on_comprar4_clicked();

    void on_comprar5_clicked();

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
