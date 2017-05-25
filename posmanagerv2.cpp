#include "posmanagerv2.h"
#include <QGeoPositionInfoSource>
#include <QTimer>
PosManagerV2::PosManagerV2()
{
    QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    if (source) {
        connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                this, SLOT(positionUpdated(QGeoPositionInfo)));
        source->startUpdates();
    }
    qDebug()<<"Actualizar posicion GPS !"<<endl;
    qDebug()<<"Latitud: "<<alt;
    qDebug()<<"Longuitud"<<lon;

    manager = new QNetworkAccessManager;

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_solicitudFinalizada(QNetworkReply *)));

    qDebug()<<"<<<Constructor clase PosManager>>>"<<endl;
}

void PosManagerV2::slot_solicitudFinalizada(QNetworkReply *reply)
{
    QByteArray ba = reply->readAll();

    int indiceComienzo = ba.indexOf("formatted_address");
    int indiceFin1 = ba.indexOf("X");
    int indiceFin2 = ba.indexOf("Córdoba");
    int inx1, inx2;

    qDebug() << "Indice comienzo domicilio : "<<  indiceComienzo;
    qDebug() << "Indice X: " << indiceFin1;
    qDebug() << "Indice Córdoba: " << indiceFin2;

    if(indiceFin1<indiceFin2)
    {
        inx1 = (indiceFin1 - 20) - indiceComienzo;
        qDebug() << "Diferencia indice inicio con x: "<< inx1;
    }
    else
    {
        inx1 =(indiceFin2 - 20) - indiceComienzo;
       qDebug() << "Diferencia indice inicio con Córdoba: "<< inx1;
    }
    inx2 =indiceComienzo + 18;
    QString direccion = ba.mid(inx2,inx1);

    emit signal_domicilioObtenido(direccion);
}

void PosManagerV2::positionUpdated(const QGeoPositionInfo &info)
{
    alt=info.coordinate().latitude();
    lon=info.coordinate().longitude();
}

void PosManagerV2::pedirDomicilio(double ll, double lg)
{
    qDebug()<<"TRAER XML";

    QString a = QString::number(ll);
    QString b = QString::number(lg);

    qDebug()<<a;
    qDebug()<<b;

    manager->get(QNetworkRequest(QUrl("https://maps.googleapis.com/maps/api/geocode/xml?latlng=" + a + "," + b+ "&key=AIzaSyAiMFncByo2gYEkkUepKtVFsXLOZIu6TIw")));
}

QStringList PosManagerV2::getLatLongGPS()
{
      QStringList cord;
      QString a = QString::number(alt);
      QString b = QString::number(lon);
      cord << a << b;
      return cord;
}

void PosManagerV2::getDomicilioActual()
{
    QString a = getLatLongGPS().at(0);
    QString b = getLatLongGPS().at(1);
    pedirDomicilio(a.toDouble(),b.toDouble());
}
