#include "interfaz.h"
#include "boton.h"
#include "mapa.h"
#include <QApplication>
#include <QNetworkProxyFactory>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QNetworkProxyFactory::setUseSystemConfiguration(true);
    Interfaz w;
    Boton setMouseTracking(bool enable);
    w.show();

    return a.exec();
}
