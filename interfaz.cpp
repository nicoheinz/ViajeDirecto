#include "interfaz.h"
#include "ui_interfaz.h"
#include "posmanagerv2.h"
#include "mapa.h"

#include <QPainter>
#include <QDebug>

Interfaz::Interfaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interfaz)
{
    ui->setupUi(this);

    posManager = new PosManagerV2;
    connect(posManager, SIGNAL(signal_domicilioObtenido(QString)),
            this, SLOT(slot_domicilioYaObtenido(QString)));


    imInterfaz.load("../ViajeDirecto-copia/fondo.jpg");

    if(imInterfaz.isNull())
        printf("La imagen no se cargo");
    else
        printf("La imagen se carga");


    manager = new QNetworkAccessManager;
    mapas = new Mapa;

    //connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(slot_procesarRespuesta(QNetworkReply *)));
    connect(ui->Boton1, SIGNAL(signal_pressed()), this, SLOT(slot_buscarMapa()));
    connect(ui->Boton1, SIGNAL(signal_pressed()), ui->mapa, SLOT(slot_dibuja()));


    //this->verMapaDondeEstoyParado();

}

void Interfaz::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0,0,imInterfaz);
}



/**
 * @brief Interfaz::slot_buscarMapa Este metodo hace lo siguiente:
 * - Obtiene el lugar donde esta el celular
 * - Buscar la parada mas cercana
 * - Descargar mapa para ver por donde hay que ir
 */
void Interfaz::slot_buscarMapa()
{
    /*QString a=QString::number(alt);
    QString l=QString::number(lon);
    qDebug()<<a;
    qDebug()<<l;
    manager->get(QNetworkRequest(QUrl("http://maps.google.com/maps/api/staticmap?center=" + alt + "," + lon + "&zoom=20&size=250x390&maptype=roadmap&markers=color:red|label:A|" + alt + "," + log + "&sensor=false&key=AIzaSyBCjEj35ftW_ZdpyvSgI2MNsaoVMmXKt9k")));

    float latitud = a.toFloat();
    float longuitud = l.toFloat();

    if(latitud!=0 && longuitud!=0)
    {
        emit signal_coordenadas(latitud,longuitud);
    }*/

}


void Interfaz::slot_domicilioYaObtenido(QString domicilio)
{

}

/**
 * @brief Interfaz::verMapaDondeEstoyParado Hace lo siguietne:
 * - Obtiene el lugar donde esta el celular
 * - Descargar mapa para ver donde estoy parado
 */
void Interfaz::verMapaDondeEstoyParado()
{
/* - Obtiene el lugar donde esta el celular
    Como se puede hacer:
    - Pedir la ubicacion a PosManager
    - Con esa ubicacion desdargar el mapa usandop la clase Mapa
*/
    posManager->getDomicilioActual();



//- Descargar mapa para ver donde estoy parado


}

