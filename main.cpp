#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;

    QStringList idiomas;

    idiomas << "Espanol" << "English" << "Japones";

    QString lang = QInputDialog::getItem(NULL, "Seleccione el Idioma", "Idioma", idiomas);

    if (lang == "English")
    {
        t.load(":/english.qm");
    }else if (lang == "Japones")
    {
        t.load(":/ja.qm");
    }
    if (lang != "Espanol")
    {
        a.installTranslator(&t);
    }


    MainWindow w;

    w.showMaximized();

    return a.exec();
}
