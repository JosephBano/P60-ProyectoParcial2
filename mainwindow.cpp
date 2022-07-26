#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDir>
#include<QFileDialog>
#include<QTime>
#include<QDateTime>
#include<QFile>
#include<QTextStream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui->area->setCurrentIndex(0);



    ui->nAdultos->setEnabled(false);
    ui->nNi->setEnabled(false);
    ui->nA3->setEnabled(false);


    // agregar Peliculas

    ruta = QFileDialog::getExistingDirectory(this,"Abrir desde ...",QDir::homePath());

    qDebug()<<ruta;

    QDir *d = new QDir();

    d->mkdir(ruta+"/compras");

    this->rutaCompras = this->ruta+"/compras";

    d->mkdir(ruta+"/facturas");

    this->rutaFacturas = this->ruta+"/facturas";

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

    // theme

    QFile sf(this->ruta+"/Estilos/Irrorater.qss");
    sf.open(QFile::ReadOnly);

    QString sS { QLatin1String(sf.readAll()) };

    sf.close();

    setStyleSheet(sS);

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

void MainWindow::Reset(){
            ui->b0->setChecked(false);

            ui->b1->setChecked(false);

            ui->b2->setChecked(false);

            ui->b3->setChecked(false);

            ui->b4->setChecked(false);

            ui->b5->setChecked(false);

            ui->b6->setChecked(false);

            ui->b7->setChecked(false);

            ui->b8->setChecked(false);

            ui->b9->setChecked(false);

            ui->b10->setChecked(false);

            ui->b11->setChecked(false);

            ui->b12->setChecked(false);

            ui->b13->setChecked(false);

            ui->b14->setChecked(false);

            ui->b15->setChecked(false);

            ui->b16->setChecked(false);

            ui->b17->setChecked(false);

            ui->b18->setChecked(false);

            ui->b19->setChecked(false);

            ui->b20->setChecked(false);

            ui->b21->setChecked(false);

            ui->b22->setChecked(false);

            ui->b23->setChecked(false);

            ui->b24->setChecked(false);

            ui->factura->setChecked(false);

            ui->resumenCompra->clear();

            ui->RAd->setChecked(false);

            ui->Rn->setChecked(false);

            ui->RAM->setChecked(false);

            ui->nAdultos->setEnabled(false);

            ui->nAdultos->setValue(0);

            ui->nNi->setEnabled(false);

            ui->nNi->setValue(0);

            ui->nA3->setEnabled(false);

            ui->nA3->setValue(0);

            ui->factura->setChecked(false);

            this->nA = 0;
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

    Reset();
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


void MainWindow::on_MostrarSala_clicked(){
    ui->area->setCurrentIndex(6);
    QStringList  rn;

    rn << "A" << "B" << "C" << "D" << "E";


    ui->fPelicula_2->setStyleSheet(p.at(0)->getFoto());
    ui->hora_2->setText(p.at(0)->getHora());
    ui->titulo_2->setText(p.at(0)->getTitulo());
    ui->min_2->setText(p.at(0)->getDuracion());


    ui->sala_2->setRowCount(5);
    ui->sala_2->setColumnCount(5);



    ui->sala_2->setVerticalHeaderLabels(rn);


    for(int i=0;i<ui->sala_2->columnCount();i++){
        ui->sala_2->setColumnWidth(i,50);
    }


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){

            ui->sala_2->setItem(i,j,new QTableWidgetItem(" "));

            if(!p.at(0)->getAsiento(i,j)){
                ui->sala_2->item(i,j)->setBackground(QBrush(Qt::blue));
            }
            else{
                ui->sala_2->item(i,j)->setBackground(QBrush(Qt::black));
            }
        }
    }

    // #3

    ui->fPelicula_3->setStyleSheet(p.at(1)->getFoto());
    ui->hora_3->setText(p.at(1)->getHora());
    ui->titulo_3->setText(p.at(1)->getTitulo());
    ui->min_3->setText(p.at(1)->getDuracion());


    ui->sala_3->setRowCount(5);
    ui->sala_3->setColumnCount(5);



    ui->sala_3->setVerticalHeaderLabels(rn);


    for(int i=0;i<ui->sala_3->columnCount();i++){
        ui->sala_3->setColumnWidth(i,50);
    }


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){

            ui->sala_3->setItem(i,j,new QTableWidgetItem(" "));

            if(!p.at(1)->getAsiento(i,j)){
                ui->sala_3->item(i,j)->setBackground(QBrush(Qt::blue));
            }
            else{
                ui->sala_3->item(i,j)->setBackground(QBrush(Qt::black));
            }
        }
    }

    // #4

    ui->fPelicula_4->setStyleSheet(p.at(2)->getFoto());
    ui->hora_4->setText(p.at(2)->getHora());
    ui->titulo_4->setText(p.at(2)->getTitulo());
    ui->min_4->setText(p.at(2)->getDuracion());


    ui->sala_4->setRowCount(5);
    ui->sala_4->setColumnCount(5);



    ui->sala_4->setVerticalHeaderLabels(rn);


    for(int i=0;i<ui->sala_4->columnCount();i++){
        ui->sala_4->setColumnWidth(i,50);
    }


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){

            ui->sala_4->setItem(i,j,new QTableWidgetItem(" "));

            if(!p.at(2)->getAsiento(i,j)){
                ui->sala_4->item(i,j)->setBackground(QBrush(Qt::blue));
            }
            else{
                ui->sala_4->item(i,j)->setBackground(QBrush(Qt::black));
            }
        }
    }

    // #5

    ui->fPelicula_5->setStyleSheet(p.at(3)->getFoto());
    ui->hora_5->setText(p.at(3)->getHora());
    ui->titulo_5->setText(p.at(3)->getTitulo());
    ui->min_5->setText(p.at(3)->getDuracion());


    ui->sala_5->setRowCount(5);
    ui->sala_5->setColumnCount(5);



    ui->sala_5->setVerticalHeaderLabels(rn);


    for(int i=0;i<ui->sala_5->columnCount();i++){
        ui->sala_5->setColumnWidth(i,50);
    }


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){

            ui->sala_5->setItem(i,j,new QTableWidgetItem(" "));

            if(!p.at(3)->getAsiento(i,j)){
                ui->sala_5->item(i,j)->setBackground(QBrush(Qt::blue));
            }
            else{
                ui->sala_5->item(i,j)->setBackground(QBrush(Qt::black));
            }
        }
    }

    // #6

    ui->fPelicula_6->setStyleSheet(p.at(4)->getFoto());
    ui->hora_6->setText(p.at(4)->getHora());
    ui->titulo_6->setText(p.at(4)->getTitulo());
    ui->min_6->setText(p.at(4)->getDuracion());


    ui->sala_6->setRowCount(5);
    ui->sala_6->setColumnCount(5);



    ui->sala_6->setVerticalHeaderLabels(rn);


    for(int i=0;i<ui->sala_6->columnCount();i++){
        ui->sala_6->setColumnWidth(i,50);
    }


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){

            ui->sala_6->setItem(i,j,new QTableWidgetItem(" "));

            if(!p.at(4)->getAsiento(i,j)){
                ui->sala_6->item(i,j)->setBackground(QBrush(Qt::blue));
            }
            else{
                ui->sala_6->item(i,j)->setBackground(QBrush(Qt::black));
            }
        }
    }

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

            qDebug()<<i<<j<<p.at(this->pos)->getAsiento(i,j);

            if(!p.at(this->pos)->getAsiento(i,j)){
                ui->sala->item(i,j)->setBackground(QBrush(Qt::blue));



            }
            else{
                // false = desocupado
                ui->sala->item(i,j)->setBackground(QBrush(Qt::black));

            }
        }
    }

    ui->area->setCurrentIndex(2);
}


void MainWindow::on_sala_cellClicked(int row, int column)
{
    if(ui->sala->item(row,column)->background() == QBrush(Qt::black)){
        ui->sala->item(row,column)->setSelected(false);
    }
    else{
        ui->sala->item(row,column)->setSelected(true);
    }


}


void MainWindow::on_aceptatAsientos_clicked(){
    ui->area->setCurrentIndex(ui->area->currentIndex()+1);



        ui->b0->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b1->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b2->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b3->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b4->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b5->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b6->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b7->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b8->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b9->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b10->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b11->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b12->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b13->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b14->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b15->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b16->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b17->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b18->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b19->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b20->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b21->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b22->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b23->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");
        ui->b24->setStyleSheet("border-image: url(:/new/prefix1/iconos/Butaca.png)");

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
//            if(ui->sala->item(i,j)->background() == QBrush(Qt::blue)){
//                ui->sala->item(i,j)->setSelected(false);
//            }

            if(ui->sala->item(i,j)->isSelected()){

                if(i == 0){
                    if(j == 0){
                        ui->b0->setChecked(true);
                        ui->b0->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;

                    }
                    if(j == 1){
                        ui->b1->setChecked(true);
                        ui->b1->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 2){
                        ui->b2->setChecked(true);
                        ui->b2->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 3){
                        ui->b3->setChecked(true);
                        ui->b3->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 4){
                        ui->b4->setChecked(true);
                        ui->b4->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                }

                if(i == 1){
                    if(j == 0){
                        ui->b5->setChecked(true);
                        ui->b5->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 1){
                        ui->b6->setChecked(true);
                        ui->b6->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 2){
                        ui->b7->setChecked(true);
                        ui->b7->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 3){
                        ui->b8->setChecked(true);
                        ui->b8->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 4){
                        ui->b9->setChecked(true);
                        ui->b9->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                }

                if(i == 2){
                    if(j == 0){
                        ui->b10->setChecked(true);
                        ui->b10->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 1){
                        ui->b11->setChecked(true);
                        ui->b11->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 2){
                        ui->b12->setChecked(true);
                        ui->b12->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 3){
                        ui->b13->setChecked(true);
                        ui->b13->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 4){
                        ui->b14->setChecked(true);
                        ui->b14->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                }

                if(i == 3){
                    if(j == 0){
                        ui->b15->setChecked(true);
                        ui->b15->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 1){
                        ui->b16->setChecked(true);
                        ui->b16->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 2){
                        ui->b17->setChecked(true);
                        ui->b17->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 3){
                        ui->b18->setChecked(true);
                        ui->b18->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 4){
                        ui->b19->setChecked(true);
                        ui->b19->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                }

                if(i == 4){
                    if(j == 0){
                        ui->b20->setChecked(true);
                        ui->b20->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 1){
                        ui->b21->setChecked(true);
                        ui->b21->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 2){
                        ui->b22->setChecked(true);
                        ui->b22->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 3){
                        ui->b23->setChecked(true);
                        ui->b23->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                    if(j == 4){
                        ui->b24->setChecked(true);
                        ui->b24->setStyleSheet("border-image: url(:/new/prefix1/iconos/asiento-de-cine.png)");
                        this->nA++;
                    }
                }
            }
        }
    }

    ui->nAsientos->setText("Asientos: "+QString::number(this->nA));
}


void MainWindow::on_terminarCompra_clicked(){
    if(ui->factura->isChecked()){
        ui->area->setCurrentIndex(ui->area->currentIndex()+1);


        QString t;

        t = ui->resumenCompra->toPlainText();

        t+= "\n\n-------------FACTURA---------------\n";

        t+="\n---Nombre: "+ui->nombre->text()+"---\n";
        t+="\n---Telefono: "+ui->telefono->text()+"---\n";
        t+="\n---Direccion: "+ui->direccion->text()+"---\n";
        t+="\n---Correo: "+ui->correo->text()+"---\n";

        ui->tFactura->setPlainText(t);


        // guardar compra

        //QString rutaCompra = this->ruta+"/compras/"+QDateTime::currentDateTime().toString().remove(" ")+".txt";

        QString r = "/"+QDateTime::currentDateTime().toString().remove(" ")+".txt";

        r.replace(":","_");

        QFile ar(rutaCompras+r);
        ar.open(QFile::WriteOnly | QFile::Text);

        if(ar.exists()){
            QString texto = " ";


            QTextStream out(&ar);

            texto = ui->resumenCompra->toPlainText();

            out<<texto;

            ar.flush();
            ar.close();
        }
        else{
            QMessageBox::critical(this,"Guardar Compra","No se pudo guardar la compra");
        }



        // guardar Factura

        //QString rutafactura = this->ruta+"/Facturas/"+QDateTime::currentDateTime().toString().remove(" ")+".txt";

         r = "/"+QDateTime::currentDateTime().toString().remove(" ")+".txt";

        r.replace(":","_");

        QFile ar1(rutaFacturas+r);

        ar1.open(QFile::WriteOnly | QFile::Text);

        if(ar1.exists()){
            QString texto1 = " ";


            QTextStream out1(&ar1);

            texto1 = ui->tFactura->toPlainText();

            out1<<texto1;

            ar1.flush();
            ar1.close();
        }
        else{
            QMessageBox::critical(this,"Guardar Factura","No se pudo guardar la Factura");
        }

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(ui->sala->item(i,j)->isSelected()){
                    p.at(this->pos)->setCompra(i,j);
                }
            }
        }

        p.at(this->pos)->FinCompra();


        qDebug()<<rutaCompras;
        qDebug()<<rutaFacturas;

    }
    else{
        ui->area->setCurrentIndex(0);

         //this->rutaCompra2 = this->ruta+"/compras/"+QDateTime::currentDateTime().toString().remove(" ")+".txt";

        QString r = "/"+QDateTime::currentDateTime().toString().remove(" ")+".txt";

        r.replace(":","_");

        qDebug()<<rutaCompras+r;

        QFile ar2(rutaCompras+r);

        ar2.open(QFile::WriteOnly | QFile::Text);

        if(ar2.exists()){
            QString texto2 = " ";


            QTextStream out2(&ar2);

            texto2 = ui->resumenCompra->toPlainText();

            out2<<texto2;

            ar2.flush();
            ar2.close();

            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(ui->sala->item(i,j)->isSelected()){
                        p.at(this->pos)->setCompra(i,j);
                    }
                }
            }


               p.at(this->pos)->FinCompra();

        }
        else{
            QMessageBox::critical(this,"Guardar Compra","No se pudo guardar la compra");
        }

        qDebug()<<rutaCompras;

    }

    Reset();

}


void MainWindow::on_bComprar_clicked(){
    if((ui->nAdultos->value()+ui->nNi->value()+ui->nA3->value()) != this->nA){
        QMessageBox::critical(this,"Error","La cantidad de asientos no coencide con las los boletos que comprara");
    }
    else{



        ui->area->setCurrentIndex(ui->area->currentIndex()+1);

        ui->cFactura->setVisible(ui->factura->isChecked());

        QString texto;

        texto+="--------------Compra--------------\n";
        texto+="---"+QDateTime::currentDateTime().toString()+"---\n";
        texto+="---ID: "+QString::number(p.at(this->pos)->getId())+"---\n";
        texto+="---Titulo: "+p.at(this->pos)->getTitulo()+"---\n";
        texto+="---Duracion: "+p.at(this->pos)->getDuracion()+"min---\n";
        texto+="---Cantidad de Asientos: "+QString::number(this->nA)+"---\n";
        texto+="---Asientos: \n";

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
    //            if(ui->sala->item(i,j)->background() == QBrush(Qt::blue)){
    //                ui->sala->item(i,j)->setSelected(false);
    //            }

                if(ui->sala->item(i,j)->isSelected()){
                    if(i == 0){
                        if(j == 0){
                            texto+="------A1\n";
                        }
                        if(j == 1){
                            texto+="------A2\n";
                        }
                        if(j == 2){
                            texto+="------A3\n";
                        }
                        if(j == 3){
                            texto+="------A4\n";
                        }
                        if(j == 4){
                            texto+="------A5\n";
                        }
                    }

                    if(i == 1){
                        if(j == 0){
                            texto+="------B1\n";
                        }
                        if(j == 1){
                            texto+="------B2\n";
                        }
                        if(j == 2){
                            texto+="------B3\n";
                        }
                        if(j == 3){
                            texto+="------B4\n";
                        }
                        if(j == 4){
                            texto+="------B5\n";
                        }
                    }

                    if(i == 2){
                        if(j == 0){
                             texto+="------C1\n";
                        }
                        if(j == 1){
                             texto+="------C2\n";
                        }
                        if(j == 2){
                             texto+="------C3\n";
                        }
                        if(j == 3){
                             texto+="------C4\n";
                        }
                        if(j == 4){
                             texto+="------C5\n";
                        }
                    }

                    if(i == 3){
                        if(j == 0){
                             texto+="------D1\n";
                        }
                        if(j == 1){
                             texto+="------D2\n";
                        }
                        if(j == 2){
                            texto+="------D3\n";
                        }
                        if(j == 3){
                             texto+="------D4\n";
                        }
                        if(j == 4){
                            texto+="------D5\n";
                        }
                    }

                    if(i == 4){
                        if(j == 0){
                             texto+="------E1\n";
                        }
                        if(j == 1){
                             texto+="------E2\n";
                        }
                        if(j == 2){
                             texto+="------E3\n";
                        }
                        if(j == 3){
                             texto+="------E4\n";
                        }
                        if(j == 4){
                             texto+="------E5\n";
                        }
                    }
                }
            }
        }

        texto+="\n---Adultos:       "+QString::number(ui->nAdultos->value())+" .... "+QString::number(ui->nAdultos->value()*7)+"$---\n";
        texto+="---Niños:           "+QString::number(ui->nNi->value())+" .... "+QString::number(ui->nNi->value()*3.5)+"$---\n";
        texto+="---Adultos Mayores: "+QString::number(ui->nA3->value())+" .... "+QString::number(ui->nA3->value()*3.5)+"$---\n";
        texto+="\n\n---------------------------------------------------------------------------\n";
        texto+="-----Total de Compra:    "+QString::number((ui->nAdultos->value()*7)+(ui->nNi->value()*3.5)+(ui->nA3->value()*3.5))+"$---";

        ui->resumenCompra->setPlainText(texto);
    }
}


void MainWindow::on_pushButton_clicked(){
    ui->area->setCurrentIndex(0);
    Reset();
}




