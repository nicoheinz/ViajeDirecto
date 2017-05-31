#include <QApplication>
#include <QNetworkProxyFactory>

#include "interfaz.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QNetworkProxyFactory::setUseSystemConfiguration(true);

    Interfaz w;

    w.setFixedSize(253,400);
    w.show();


    return a.exec();
}
