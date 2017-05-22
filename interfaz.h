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
#include "myclass.h"
#include "posmanager.h"


namespace Ui {
class Interfaz;
}

class Interfaz : public QWidget
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = 0);
    MyClass m;

    void paintEvent(QPaintEvent *);

    double alt;
    double lon;

    QNetworkAccessManager *manager;
    Mapa *mapas;

    PosManager *pm;

private  slots:
    void slot_boton();
    void slot_salir();
    void positionUpdated(const QGeoPositionInfo &info);
    void slot_procesarRespuesta(QNetworkReply * reply);
    void slot_buscarMapa();

private:
    Ui::Interfaz *ui;
    QImage imInterfaz;

signals:
    void signal_coordenadas(float lt, float lg);

};

#endif // INTERFAZ_H
