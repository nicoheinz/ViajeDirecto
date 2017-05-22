#ifndef POSICION_H
#define POSICION_H

#include <QGeoPositionInfoSource>
#include <QDebug>

#include <QWidget>
#include "myclass.h"
#include "posmanager.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "mapas.h"


namespace Ui {
class Posicion;
}

class Posicion : public QWidget
{
    Q_OBJECT

public:
    explicit Posicion(QWidget *parent = 0);
    ~Posicion();
    MyClass m;

    double alt;
    double lon;

    QNetworkAccessManager *manager;
    Mapas * mapas;

    PosManager *pm;

private slots:
    void positionUpdated(const QGeoPositionInfo &info);
    void slot_procesarRespuesta(QNetworkReply * reply);
    void slot_buscarMapa();

    void slot_setLineEdit(QString);
    void qDebug_gets();

private:
    Ui::Posicion *ui;

signals:
    void signal_coordenadas(float lt, float lg);

};

#endif // POSICION_H
