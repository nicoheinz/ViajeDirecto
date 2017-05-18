#include "mapa.h"
#include "ui_mapa.h"
#include "interfaz.h"

#include <QPainter>


Mapa::Mapa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mapa)
{
    ui->setupUi(this);

    imMapa.load("../ViajeDirecto/mapa.jpg");

    if(imMapa.isNull())
        printf("La imagen no se cargo");
    else
        printf("La imagen se carga");

    this->repaint();
    this->hide();

}

Mapa::~Mapa()
{
    delete ui;
}

void Mapa::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0, 0, imMapa);
}
