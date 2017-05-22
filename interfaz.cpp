#include "interfaz.h"
#include "ui_interfaz.h"

#include <QPainter>
#include <QDebug>

Interfaz::Interfaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interfaz)
{
    ui->setupUi(this);

    imInterfaz.load("../ViajeDirecto-master/fondo.jpg");

    if(imInterfaz.isNull())
        printf("La imagen no se cargo");
    else
        printf("La imagen se carga");

    pm = new PosManager;

//    ui->widget->setFixedSize(253,400);
    manager = new QNetworkAccessManager;
    mapas = new Mapa;

    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(slot_procesarRespuesta(QNetworkReply *)));
    connect(ui->Boton1, SIGNAL(signal_pressed()), this, SLOT(slot_buscarMapa()));

    QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    if (source) {
        connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                this, SLOT(positionUpdated(QGeoPositionInfo)));
        source->startUpdates();
    }

    alt = -31.4207166;
    lon = -64.1833505;
}

void Interfaz::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
//    resize(imInterfaz.size());
    painter.drawImage(0,0,imInterfaz);
}


void Interfaz::slot_boton()
{
//    ui->widget->show();
    //ui->Boton1->hide();
}

void Interfaz::slot_salir()
{
//    this->close();
}
void Interfaz::positionUpdated(const QGeoPositionInfo &info)
{
//    alt=info.coordinate().latitude();
//    lon=info.coordinate().longitude();


    alt = -31.4207166;
    lon = -64.1833505;
}

void Interfaz::slot_procesarRespuesta(QNetworkReply * reply)
{
    QImage im = QImage::fromData(reply->readAll());
    ui->widget->setMapa(im);

}

void Interfaz::slot_buscarMapa()
{
    QString a=QString::number(alt);
    QString l=QString::number(lon);

    manager->get(QNetworkRequest(QUrl("http://maps.google.com/maps/api/staticmap?center="+ a + " , " + l +"&zoom=12&size=512x512&maptype=roadmap&markers=color:red|label:A|"+ a + " , " + l +"&sensor=false&key=AIzaSyBCjEj35ftW_ZdpyvSgI2MNsaoVMmXKt9k")));

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

