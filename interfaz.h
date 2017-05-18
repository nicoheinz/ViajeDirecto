#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QWidget>
#include <QDebug>
#include <QImage>
#include <QPaintEvent>


namespace Ui {
class Interfaz;
}

class Interfaz : public QWidget
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = 0);
    ~Interfaz();
    void paintEvent(QPaintEvent *);

private  slots:
    void slot_boton();
    void slot_salir();
private:
    Ui::Interfaz *ui;
    QImage imInterfaz;

};

#endif // INTERFAZ_H
