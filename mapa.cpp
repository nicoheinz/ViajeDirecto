#include "mapa.h"
#include "ui_mapa.h"

Mapa::Mapa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mapa)
{
    ui->setupUi(this);
}
void Mapa::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0,0,im);
}

void Mapa::setMapa(QImage im)
{
    this->im = im;
    this->repaint();
}
