#-------------------------------------------------
#
# Project created by QtCreator 2017-05-21T19:49:30
#
#-------------------------------------------------

QT       += core gui network positioning

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColectivosUbpPosManager
TEMPLATE = app


SOURCES += \
    main.cpp \
    mapa.cpp \
    mapas.cpp \
    posicion.cpp \
    posmanager.cpp

HEADERS  += \
    mapa.h \
    mapas.h \
    myclass.h \
    posicion.h \
    posmanager.h

FORMS    += \
    posicion.ui
