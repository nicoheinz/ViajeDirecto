#include "mapas.h"

Mapas::Mapas(QWidget *parent) : QWidget(parent)
{

}
void Mapas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0,0,im);
}

void Mapas::setMapa(QImage im)
{
    this->im = im;
    this->repaint();
}
