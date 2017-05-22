#include "posicion.h"
#include "ui_posicion.h"
#include <QDebug>
Posicion::Posicion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Posicion)
{
    ui->setupUi(this);

    pm = new PosManager;
    manager = new QNetworkAccessManager;
    mapas = new Mapas;

    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(slot_procesarRespuesta(QNetworkReply *)));
    connect(ui->leDomicilio, SIGNAL(returnPressed()), this, SLOT(slot_buscarMapa()));
    connect(ui->pbActualizar, SIGNAL(clicked()), this, SLOT(slot_buscarMapa()));
    connect(ui->pbGets, SIGNAL(clicked()), this, SLOT(qDebug_gets()));

    QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    if (source) {
        connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                this, SLOT(positionUpdated(QGeoPositionInfo)));
        source->startUpdates();
    }

    alt = -31.4207166;
    lon = -64.1833505;
}

Posicion::~Posicion()
{
    delete ui;
}
void Posicion::positionUpdated(const QGeoPositionInfo &info)
{
//    alt=info.coordinate().latitude();
//    lon=info.coordinate().longitude();


    alt = -31.4207166;
    lon = -64.1833505;
}

void Posicion::slot_procesarRespuesta(QNetworkReply * reply)
{
    QImage im = QImage::fromData(reply->readAll());
    ui->widget->setMapa(im);

}

void Posicion::slot_buscarMapa()
{
    QString a=QString::number(alt);
    QString l=QString::number(lon);

    manager->get(QNetworkRequest(QUrl("http://maps.google.com/maps/api/staticmap?center="+ a + " , " + l +"&zoom=15&size=512x512&maptype=roadmap&markers=color:red|label:A|"+ a + " , " + l +"&sensor=false&key=AIzaSyBCjEj35ftW_ZdpyvSgI2MNsaoVMmXKt9k")));

    qDebug() << "SLOT BUSCAR MAPAAAAAAAAAAAAAAA";
    qDebug() << a;
    qDebug() << l;

    float latitud = a.toFloat();
    float longuitud = l.toFloat();

    if(latitud!=0 && longuitud!=0)
    {
        emit signal_coordenadas(latitud,longuitud);
    }
}




void Posicion::slot_setLineEdit(QString string)
{
    ui->leDomicilio->setText(string);
}

void Posicion::qDebug_gets()
{
//    QString domicilio = pm->getDomicilioActual();
//    pm->setLatLongGPS(1.2312312,2.12312321);
//    pm->setDomicilioActual("donato alvarez 7685");
//    qDebug()<<"----------DOMICILIO ACTUAL--------------" << pm->getDomicilioActual();
//    qDebug()<<"----------Lat and Long actual-----------"<< pm->getLatLongGPS();
}


