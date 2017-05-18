#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QPaintEvent>
#include <QPushButton>
#include <QImage>
#include <QMouseEvent>
#include <QDebug>

namespace Ui {
class Boton;
}

class Boton : public QWidget
{
    Q_OBJECT

public:
    explicit Boton(QWidget *parent = 0);
    ~Boton();
    void mousePressEvent(QMouseEvent* event);

signals:
    void signal_pressed();
    void signal_salir();


private:
    Ui::Boton *ui;
    void paintEvent(QPaintEvent *);
    QImage im1;
    QMouseEvent *mouse;
};

#endif // BOTON_H
