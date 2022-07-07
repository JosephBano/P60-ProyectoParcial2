#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

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
    //void on_info1_textEdited(const QString &arg1);

    void on_info1_inputRejected();

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
