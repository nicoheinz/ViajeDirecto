#include "boton.h"
#include "ui_boton.h"
#include <QPainter>
#include <QColor>


Boton::Boton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Boton)
{
    ui->setupUi(this);
    im1.load("../ViajeDirecto/escudo.png");

    if(im1.isNull())
        printf("La imagen no se cargo");
    else
        printf("La imagen se carga");

    this->repaint();


}

Boton::~Boton()
{
    delete ui;
}


void Boton::mousePressEvent(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
         emit signal_pressed();

    if(event->button()== Qt::RightButton)
         emit signal_salir();
}




void Boton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawImage(0,0,im1);


}
