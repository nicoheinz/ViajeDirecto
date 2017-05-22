#include <QApplication>
#include <QNetworkProxyFactory>

#include "posmanager.h"
#include "interfaz.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QNetworkProxyFactory::setUseSystemConfiguration(true);

    Interfaz w;
//    w.setFixedSize(253,400);
    w.show();

//    PosManager pm;


//    QObject::connect(&w,SIGNAL(signal_coordenadas(float,float)),&pm,SLOT(pedirDomicilio(float,float)));
//    QObject::connect(&pm,SIGNAL(signal_domicilioObtenido(QString)),&w,SLOT(direccionLista(QString)));

    return a.exec();
}
