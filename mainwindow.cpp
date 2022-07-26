#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDir>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui->area->setCurrentIndex(0);

//    ui->b1->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b2->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b3->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b4->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b5->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b6->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b7->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b8->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b9->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b10->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b11->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b12->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b13->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b14->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b15->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b16->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b17->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b18->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b19->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
//    ui->b20->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");

    ui->nAdultos->setEnabled(false);
    ui->nNi->setEnabled(false);
    ui->nA3->setEnabled(false);


    // agregar Peliculas

    ruta = QFileDialog::getExistingDirectory(this,"Guardar Proyecto en ...",QDir::homePath());

    //qDebug()<<ruta;

    Pelicula *a = new Pelicula();
    a->setId(1);
    a->setTitulo("Los Minios");
    a->setDuracion("117");
    a->setHora("14:30");
    a->setEstreno("true");
    a->setFoto("border-image: url(:/new/prefix1/iconos/MiniosCartelera.jpg)");
    a->CrearAsientos(ruta+"/asientos/p1.csv");

    p.append(a);


    Pelicula *a1 = new Pelicula();
    a1->setId(2);
    a1->setTitulo("Thor: Love and Thunder");
    a1->setDuracion("157");
    a1->setHora("14:30");
    a1->setEstreno("true");
    a1->setFoto("border-image: url(:/new/prefix1/iconos/ThorCartelera.jpg)");
    a1->CrearAsientos(ruta+"/asientos/p2.csv");

    p.append(a1);

    Pelicula *a2 = new Pelicula();
    a2->setId(3);
    a2->setTitulo("SE7VEN");
    a2->setDuracion("157");
    a2->setHora("14:30");
    a2->setEstreno("true");
    a2->setFoto("border-image: url(:/new/prefix1/iconos/SevenCartelera.jpg)");
    a2->CrearAsientos(ruta+"/asientos/p3.csv");

    p.append(a2);

    Pelicula *a3 = new Pelicula();
    a3->setId(4);
    a3->setTitulo("Ligtyear");
    a3->setDuracion("157");
    a3->setHora("14:30");
    a3->setEstreno("true");
    a3->setFoto("border-image: url(:/new/prefix1/iconos/LightyearCartelera.jpg)");
    a3->CrearAsientos(ruta+"/asientos/p4.csv");

    p.append(a3);

    Pelicula *a4 = new Pelicula();
    a4->setId(5);
    a4->setTitulo("Jurassic World");
    a4->setDuracion("157");
    a4->setHora("14:30");
    a4->setEstreno("true");
    a4->setFoto("border-image: url(:/new/prefix1/iconos/JurworldCartelera.jpg)");
    a4->CrearAsientos(ruta+"/asientos/p5.csv");

    p.append(a4);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CrearCartelera(){
    ui->tableWidget->setRowHeight(0,350);

    for(int i=0;i<p.size();i++){
       ui->tableWidget->setColumnCount(ui->tableWidget->columnCount()+1);
       ui->tableWidget->setColumnWidth(i,180);
       ui->tableWidget->setCellWidget(0,i,p.at(i));
    }
}


void MainWindow::on_c1_clicked(){
    ui->area->setCurrentIndex(1);
}


void MainWindow::on_c2_clicked(){
    ui->area->setCurrentIndex(1);
}

void MainWindow::on_c3_clicked(){
    ui->area->setCurrentIndex(1);
}


void MainWindow::on_c4_clicked(){
    ui->area->setCurrentIndex(1);
}


void MainWindow::on_c5_clicked(){
    ui->area->setCurrentIndex(1);
}

void MainWindow::on_RAd_clicked(){
    ui->nAdultos->setEnabled(!ui->nAdultos->isEnabled());
}

void MainWindow::on_Rn_clicked(){
    ui->nNi->setEnabled(!ui->nNi->isEnabled());
}

void MainWindow::on_RAM_clicked(){
    ui->nA3->setEnabled(!ui->nA3->isEnabled());
}


void MainWindow::on_mas_clicked()
{
    ui->area->setCurrentIndex(0);
}





void MainWindow::on_Salir_clicked(){
    QMessageBox::StandardButton reply;
    QMessageBox messageBox;

    reply = messageBox.question(this, "Salir", "Estas Seguro que quieres Salir?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes){
        //QMessageBox::information(this,"Saliendo","Gracias por visitarnos");
        close();
    }
}


void MainWindow::on_mostrarCartelera_clicked()
{

    CrearCartelera();

    ui->area->setCurrentIndex(1);

    ui->factura->setChecked(false);

}


void MainWindow::on_MostrarSala_clicked()
{

//    for(int i=0;i<ui->sala->columnCount();i++){
//        ui->sala->setColumnWidth(i,50);
//    }

//    ui->fPelicula->setStyleSheet(p.at(0)->getFoto());
//    ui->hora->setText(p.at(0)->getHora());
//    ui->titulo->setText(p.at(0)->getTitulo());
//    ui->min->setText(p.at(0)->getDuracion());

//    QTableWidgetItem * item = new QTableWidgetItem();

////    item->setIcon(QIcon(":/new/prefix1/iconos/asiento-de-cine.png"));

//    ui->sala->setItem(0,0,item);

//    ui->sala->item(0,0)->setBackground(QBrush(Qt::blue));

//    ui->area->setCurrentIndex(2);

}



void MainWindow::on_ComprarBoletos_clicked(){
    CrearCartelera();
    ui->area->setCurrentIndex(1);

}


void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column){

    this->pos = column;

    ui->sala->setRowCount(0);
    ui->sala->setColumnCount(0);


    ui->fPelicula->setStyleSheet(p.at(this->pos)->getFoto());
    ui->hora->setText(p.at(this->pos)->getHora());
    ui->titulo->setText(p.at(this->pos)->getTitulo());
    ui->min->setText(p.at(this->pos)->getDuracion());

    //QTableWidgetItem * item = new QTableWidgetItem();

//    item->setIcon(QIcon(":/new/prefix1/iconos/asiento-de-cine.png"));

    ui->sala->setRowCount(5);
    ui->sala->setColumnCount(5);

    QStringList  rn;

    rn << "A" << "B" << "C" << "D" << "E";

    ui->sala->setVerticalHeaderLabels(rn);


    for(int i=0;i<ui->sala->columnCount();i++){
        ui->sala->setColumnWidth(i,50);
    }


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){

            ui->sala->setItem(i,j,new QTableWidgetItem(" "));

            //qDebug()<<i<<j<<p.at(this->pos)->getAsiento(i,j);

            if(p.at(this->pos)->getAsiento(i,j)){
                ui->sala->item(i,j)->setBackground(QBrush(Qt::blue));

               //ui->sala->item(i,j)->setSelected(false);

            }
            else{
                ui->sala->item(i,j)->setBackground(QBrush(Qt::black));
                //ui->sala->item(i,j)->setSelected(true);
            }
        }
    }




    ui->area->setCurrentIndex(2);
}


void MainWindow::on_sala_cellClicked(int row, int column)
{
    if(ui->sala->item(row,column)->background() == QBrush(Qt::blue)){
        ui->sala->item(row,column)->setSelected(false);
    }

    if(ui->sala->item(row,column)->isSelected()){
        if(row == 0){
            if(column == 0){
                ui->b0->setChecked(!ui->b0->isChecked());
            }
            if(column == 1){
                ui->b1->setChecked(!ui->b0->isChecked());
            }
            if(column == 2){
                ui->b2->setChecked(!ui->b0->isChecked());
            }
            if(column == 3){
                ui->b3->setChecked(!ui->b0->isChecked());
            }
            if(column == 4){
                ui->b4->setChecked(!ui->b0->isChecked());
            }
        }

        if(row == 1){
            if(column == 0){
                ui->b5->setChecked(!ui->b0->isChecked());
            }
            if(column == 1){
                ui->b6->setChecked(!ui->b0->isChecked());
            }
            if(column == 2){
                ui->b7->setChecked(!ui->b0->isChecked());
            }
            if(column == 3){
                ui->b8->setChecked(!ui->b0->isChecked());
            }
            if(column == 4){
                ui->b9->setChecked(!ui->b0->isChecked());
            }
        }

        if(row == 2){
            if(column == 0){
                ui->b10->setChecked(!ui->b0->isChecked());
            }
            if(column == 1){
                ui->b11->setChecked(!ui->b0->isChecked());
            }
            if(column == 2){
                ui->b12->setChecked(!ui->b0->isChecked());
            }
            if(column == 3){
                ui->b13->setChecked(!ui->b0->isChecked());
            }
            if(column == 4){
                ui->b14->setChecked(!ui->b0->isChecked());
            }
        }

        if(row == 3){
            if(column == 0){
                ui->b15->setChecked(!ui->b0->isChecked());
            }
            if(column == 1){
                ui->b16->setChecked(!ui->b0->isChecked());
            }
            if(column == 2){
                ui->b17->setChecked(!ui->b0->isChecked());
            }
            if(column == 3){
                ui->b18->setChecked(!ui->b0->isChecked());
            }
            if(column == 4){
                ui->b19->setChecked(!ui->b0->isChecked());
            }
        }

        if(row == 4){
            if(column == 0){
                ui->b20->setChecked(!ui->b0->isChecked());
            }
            if(column == 1){
                ui->b21->setChecked(!ui->b0->isChecked());
            }
            if(column == 2){
                ui->b22->setChecked(!ui->b0->isChecked());
            }
            if(column == 3){
                ui->b23->setChecked(!ui->b0->isChecked());
            }
            if(column == 4){
                ui->b24->setChecked(!ui->b0->isChecked());
            }
        }
    }
}


void MainWindow::on_aceptatAsientos_clicked(){
    ui->area->setCurrentIndex(ui->area->currentIndex()+1);


}


void MainWindow::on_terminarCompra_clicked(){
    if(ui->factura->isChecked()){
        ui->area->setCurrentIndex(ui->area->currentIndex()+1);
    }
    else{
        ui->area->setCurrentIndex(0);
    }

}


void MainWindow::on_bComprar_clicked()
{
    ui->area->setCurrentIndex(ui->area->currentIndex()+1);
}

