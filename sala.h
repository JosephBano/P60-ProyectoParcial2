#ifndef SALA_H
#define SALA_H

#include<iostream>
#include <QWidget>

using namespace std;

class sala{
    private:
        bool a[5][5];
        QString ruta;
    public:
        sala();
        bool getValue(int,int);
        void setValue(int,int,bool);
        void Create(QString);
        void Compro(int,int);

};

#endif // SALA_H
