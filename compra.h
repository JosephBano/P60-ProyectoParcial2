#ifndef COMPRA_H
#define COMPRA_H

#include <QWidget>

class compra{
    private:
        int pID;
        QString ac[5][5];
    public:
        compra();
        void AddAsiento(int,int);
};

#endif // COMPRA_H
