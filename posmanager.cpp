#include "posmanager.h"

PosManager::PosManager()
{

    manager = new QNetworkAccessManager;

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_solicitudFinalizada(QNetworkReply *)));
}

QStringList PosManager::getLatLongGPS() const
{
    QStringList cord;
    QString a = QString::number(ll);

    QString b = QString::number(lg);
    cord << a << b;
    return cord;
}

void PosManager::setLatLongGPS(float ll, float lg)
{
    QString a = QString::number(ll);

    QString b = QString::number(lg);
    QStringList coordenadas;
    coordenadas << a<< b;
}

void PosManager::getDomicilioActual()
{
    QString a = getLatLongGPS().at(0);
    QString b = getLatLongGPS().at(1);
    pedirDomicilio(a.toFloat(),b.toFloat());
}

void PosManager::setDomicilioActual(QString dom)
{
    domicilio = dom;
    qDebug()<<"setDomicilioActual:" <<dom;
}

void PosManager::slot_solicitudFinalizada(QNetworkReply *reply)
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
        domicilio = ba.mid(inx2,inx1);
        qDebug()<<"Domicilio en la clase posmanager " <<domicilio;
        setDomicilioActual(domicilio);
        emit signal_domicilioObtenido(domicilio);
}

void PosManager::pedirDomicilio(float ll, float lg)
{
        qDebug()<<"TRAER XML";

        QString a = QString::number(ll);

        QString b = QString::number(lg);

        qDebug()<<a;
        qDebug()<<b;

        manager->get(QNetworkRequest(QUrl("https://maps.googleapis.com/maps/api/geocode/xml?latlng=" + a + "," + b+ "&key=AIzaSyAiMFncByo2gYEkkUepKtVFsXLOZIu6TIw")));
}
