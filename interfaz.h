#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QWidget>
#include <QDebug>
#include <QImage>
#include <QPaintEvent>
#include <QGeoPositionInfoSource>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "mapa.h"
#include "posmanagerv2.h"


namespace Ui {
class Interfaz;
}

class Interfaz : public QWidget
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = 0);
    //MyClass m;
    PosManagerV2 *posManager;
    void paintEvent(QPaintEvent *);

    double alt;
    double lon;

    QNetworkAccessManager *manager;
    Mapa *mapas;

private  slots:
    void slot_buscarMapa();
    void slot_domicilioYaObtenido(QString domicilio);

private:
    Ui::Interfaz *ui;
    QImage imInterfaz;

    void verMapaDondeEstoyParado();

signals:
    void signal_coordenadas(float lt, float lg);

};

#endif // INTERFAZ_H
