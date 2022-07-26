#ifndef PELICULA_H
#define PELICULA_H

#include <QWidget>
#include"sala.h"

namespace Ui {
class Pelicula;
}

class Pelicula : public QWidget
{
    Q_OBJECT

public:
    explicit Pelicula(QWidget *parent = nullptr);
    ~Pelicula();
    void setTitulo(QString);
    void setDuracion(QString);
    void setFoto(QString);
    void setId(int);
    void setEstreno(bool);
    void setHora(QString);
    QString getTitulo();
    QString getDuracion();
    QString getFoto();
    int getId();
    bool getEstreno();
    QString getHora();
    void Imprimir();
    void CrearAsientos(QString);
    void setCompra(int,int);
    bool getAsiento(int,int);
    void FinCompra();

private:
    Ui::Pelicula *ui;
    QString Titulo,Duracion;
    QString Foto;
    int id;
    bool estreno;
    QString hora;
    sala *s = new sala();
    QString ruta;
};

#endif // PELICULA_H
