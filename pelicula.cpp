#include "pelicula.h"
#include "ui_pelicula.h"
#include<QDebug>

Pelicula::Pelicula(QWidget *parent) :QWidget(parent), ui(new Ui::Pelicula){
    ui->setupUi(this);

}

Pelicula::~Pelicula(){
    delete ui;
}

void Pelicula::setTitulo(QString t){
    this->Titulo = t;
    ui->Titulo->setText(t);
}

void Pelicula::setDuracion(QString d){
    this->Duracion = d;
    ui->duracion->setText(d);
}

void Pelicula::setFoto(QString f){
    this->Foto = f;
    ui->foto->setStyleSheet(f);
}

void Pelicula::setId(int id){
    this->id = id;

}

void Pelicula::setEstreno(bool e){
    this->estreno = e;
    if(e){
        ui->Estreno->setText("Estreno");
    }
    else{
        ui->Estreno->setText("No Estreno");
    }
}

void Pelicula::setHora(QString h){
    this->hora = h;
    ui->Hora->setText(h);
}

QString Pelicula::getTitulo(){
    return this->Titulo;
}

QString Pelicula::getDuracion(){
    return this->Duracion;
}

QString Pelicula::getFoto(){
    return this->Foto;
}

int Pelicula::getId(){
    return this->id;
}

bool Pelicula::getEstreno(){
    return this->estreno;
}

QString Pelicula::getHora(){
    return this->hora;
}

void Pelicula::Imprimir(){
    qDebug()<<"Titulo: "<<this->Titulo;
    qDebug()<<"Duracion: "<<this->Duracion;
    qDebug()<<"Foto: "<<this->Foto;
    qDebug()<<"ID: "<<this->id;
    qDebug()<<"Estreno: "<<this->estreno;
    qDebug()<<"Hora: "<<this->hora;
    qDebug()<<"Asientos\n";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            qDebug()<<s->getValue(i,j);
        }
    }
}

void Pelicula::CrearAsientos(QString r){
    s->Create(r);
    this->ruta = r;
}

void Pelicula::setCompra(int i, int j){
    s->Compro(i,j);
}

bool Pelicula::getAsiento(int i, int j){
    return s->getValue(i,j);
}

void Pelicula::FinCompra()
{
    s->FinCompra();
}


