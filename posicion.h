#ifndef POSICION_H
#define POSICION_H

#include <QGeoPositionInfoSource>
#include <QDebug>

#include <QWidget>

#include "posmanagerv2.h"

namespace Ui {
class Posicion;
}

class Posicion : public QWidget
{
    Q_OBJECT

public:
    explicit Posicion(QWidget *parent = 0);
    ~Posicion();

    //DECLARO UN OBJETO POSMANAGER
    PosManagerV2 *posManager;

    bool dsk;

private:
    Ui::Posicion *ui;

private slots:
    void setLineEdit(QString dom);
    void actualizarPosicion();

};

#endif // POSICION_H
