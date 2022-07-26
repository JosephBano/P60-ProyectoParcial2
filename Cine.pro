QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    pelicula.cpp \
    sala.cpp

HEADERS += \
    mainwindow.h \
    pelicula.h \
    sala.h

FORMS += \
    mainwindow.ui \
    pelicula.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    iconos.qrc \
    translations.qrc

DISTFILES += \
    Estilos/Diffnes.qss \
    Estilos/Irrorater.qss \
    asientos/p1.csv \
    asientos/p2.csv \
    asientos/p3.csv \
    asientos/p4.csv \
    asientos/p5.csv
