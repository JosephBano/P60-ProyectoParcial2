#include "sala.h"
#include<fstream>
#include<QDebug>
#include<QFile>

sala::sala(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            this->a[i][j] = false;
        }
    }
}

bool sala::getValue(int i, int j){
    return a[i][j];
}

void sala::setValue(int i, int j, bool v){
    this->a[i][j] = v;
}

void sala::Create(QString r){

    this->ruta = r;

    QFile a(r);

    a.open(QFile::ReadOnly);

    if(a.exists()){

        QTextStream out(&a);
        QString texto = out.readAll();



        QStringList s = texto.split("\r\n");

        //qDebug()<<s;




        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(s.at(i).at(j) == '1'){
                    setValue(i,j,true);
                }
                else{
                   setValue(i,j,false);
                }


                qDebug()<<getValue(i,j);
            }
        }

        a.flush();
        a.close();

    }
}

void sala::Compro(int i, int j){
    this->a[i][j] = true;

    QFile a(this->ruta);
    QString texto = " ";


            a.open(QFile::WriteOnly | QFile::Text);
            QTextStream out(&a);

    for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(this->a[i][j]){
                        texto += "1,";
                    }
                    else{
                        texto += "0,";
                    }
                }
                texto+="\n";
                out << texto;
                texto.clear();
            }
            a.flush();
            a.close();
}
