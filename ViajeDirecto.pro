#-------------------------------------------------
#
# Project created by QtCreator 2017-05-15T17:25:50
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ViajeDirecto
TEMPLATE = app


SOURCES += main.cpp\
        interfaz.cpp \
    boton.cpp \
    mapa.cpp

HEADERS  += interfaz.h \
    boton.h \
    mapa.h

FORMS    += interfaz.ui \
    boton.ui \
    mapa.ui
