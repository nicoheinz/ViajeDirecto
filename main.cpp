#include "posicion.h"
#include "posmanager.h"
#include "myclass.h"
#include <QApplication>
#include "myclass.h"
#include <QNetworkProxyFactory>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Posicion w;
    w.show();
    PosManager pm;
    QNetworkProxyFactory::setUseSystemConfiguration(true);

    QObject::connect(&w,SIGNAL(signal_coordenadas(float,float)),&pm,SLOT(pedirDomicilio(float,float)));
    QObject::connect(&pm,SIGNAL(signal_domicilioObtenido(QString)),&w,SLOT(direccionLista(QString)));
    QObject::connect(&pm,SIGNAL(signal_domicilioObtenido(QString)),&w,SLOT(slot_setLineEdit(QString)));

    return a.exec();
}
