#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"pelicula.h"
#include"compra.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void CrearCartelera();

private slots:
    void on_c1_clicked();

    void on_c2_clicked();

    void on_c3_clicked();

    void on_c4_clicked();

    void on_c5_clicked();


    void on_RAd_clicked();

    void on_Rn_clicked();

    void on_RAM_clicked();

    void on_mas_clicked();


    void on_Salir_clicked();

    void on_mostrarCartelera_clicked();

    void on_MostrarSala_clicked();

    void on_ComprarBoletos_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_sala_cellClicked(int row, int column);

    void on_aceptatAsientos_clicked();

    void on_terminarCompra_clicked();

    void on_bComprar_clicked();

private:
    Ui::MainWindow *ui;
    QString AD = ":/new/prefix1/iconos/asiento-de-cine.png";
    QString AO = ":/new/prefix1/iconos/Butaca.png";
    QVector<Pelicula *> p;
    QVector<compra *> c;
    QString ruta;
    int pos;
};
#endif // MAINWINDOW_H
