#include "interfaz.h"
#include "ui_interfaz.h"
#include "mapa.h"

#include <QPainter>

Interfaz::Interfaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interfaz)
{
    ui->setupUi(this);

    imInterfaz.load("../ViajeDirecto/fondo.jpg");

    if(imInterfaz.isNull())
        printf("La imagen no se cargo");
    else
        printf("La imagen se carga");

    this->repaint();

    connect(ui->Boton1, SIGNAL(signal_pressed()),this,SLOT(slot_boton()));
    connect(ui->Boton1, SIGNAL(signal_salir()),this,SLOT(slot_salir()));
}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    resize(imInterfaz.size());
    painter.drawImage(0,0,imInterfaz);
}


void Interfaz::slot_boton()
{
    ui->widget->show();
    //ui->Boton1->hide();
}

void Interfaz::slot_salir()
{
    this->close();
}
