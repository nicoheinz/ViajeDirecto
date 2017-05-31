#include "mapa.h"
#include "ui_mapa.h"
#include "posmanagerv2.h"
#include <QPainter>
#include <QTimer>



Mapa::Mapa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mapa)
{
    ui->setupUi(this);
    ui->spinBox->hide();
    ManagerMapa = new QNetworkAccessManager;
    connect(ManagerMapa, SIGNAL(finished(QNetworkReply *)), this, SLOT(slot_procesarRespuesta(QNetworkReply *)));
    connect(ui->spinBox,SIGNAL(valueChanged(int )),this,SLOT(slot_dibuja()));

    QTimer::singleShot(0.01, this, SLOT(slot_dibuja()));




}

void Mapa::setMapa(QImage im)
{
    this->im = im;
    this->repaint();
}

void Mapa::slot_procesarRespuesta(QNetworkReply * reply)
{
    imMapa = QImage::fromData(reply->readAll());
    this->repaint();
}

void Mapa::slot_dibuja()
{   PosManagerV2 *posmanager= new PosManagerV2;
    ui->spinBox->show();

    ui->spinBox->setRange(0,20);
    int va2= ui->spinBox->value();

    QString valor= QString::number(va2);

    QString altitud= QString::number(posmanager->getAltitud());
    QString longuitud= QString::number(posmanager->getLongitud());



    ManagerMapa->get(QNetworkRequest(QUrl("http://maps.google.com/maps/api/staticmap?center=" + altitud + "," + longuitud + "&zoom= " + valor + " &size=250x390&maptype=roadmap&markers=color:red|label:A|" + altitud + "," + longuitud + "&sensor=false&key=AIzaSyBCjEj35ftW_ZdpyvSgI2MNsaoVMmXKt9k")));
    //ManagerMapa->get(QNetworkRequest(QUrl("http://maps.google.com/maps/api/staticmap?center=-31.338360,-64.257276&zoom= " + valor + " &size=250x390&maptype=roadmap&markers=color:red|label:A|-31.338360,-64.257276&sensor=false&key=AIzaSyBCjEj35ftW_ZdpyvSgI2MNsaoVMmXKt9k")));
}


void Mapa::getMapa(QUrl url)
{

    ManagerMapa->get(QNetworkRequest(QUrl(url)));


}

void Mapa::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0,0,imMapa);
}
