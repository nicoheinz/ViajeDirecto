#include "mapa.h"

Mapa::Mapa()
{

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
