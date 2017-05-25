#include "posicion.h"
#include "ui_posicion.h"
#include <QDebug>
Posicion::Posicion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Posicion)
{
    ui->setupUi(this);

    posManager = new PosManagerV2;
//    QStringList list = posManager->getLatLongGPS();
//    QString a = posManager->getLatLongGPS().at(0);
//    QString b = posManager->getLatLongGPS().at(1);

//    float latitud = a.toFloat();
//    float longuitud = a.toFloat();

    connect(ui->pbActualizar,SIGNAL(clicked(bool)),this,SLOT(actualizarPosicion()));

    connect(posManager,SIGNAL(signal_domicilioObtenido(QString)),this,SLOT(setLineEdit(QString)));

    //Aca se setea si vamos a utilizar el gps de un celular o vamos a enviar latitud y longuitud manualmente
    dsk = false;
}

Posicion::~Posicion()
{
    delete ui;
}

void Posicion::setLineEdit(QString dom)
{
    qDebug()<<"setLineEdit"<<endl;
    ui->leDomicilio->setText(dom);
}

void Posicion::actualizarPosicion()
{
    qDebug()<<"ACTUALIZAR POSICION EN VENTANA"<<endl<<endl;
    double a;
    double b;
    if(dsk)
    {
        a = posManager->getAltitud();
        b = posManager->getLongitud();

        qDebug()<<a;
        qDebug()<<b;
    }
    else
    {
        a = -31.4191074;
        b = -64.1960073;
    }
    posManager->pedirDomicilio(a,b);
}



