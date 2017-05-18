#ifndef MAPA_H
#define MAPA_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>

namespace Ui {
class Mapa;
}

class Mapa : public QWidget
{
    Q_OBJECT

public:
    explicit Mapa(QWidget *parent = 0);
    ~Mapa();
    void paintEvent(QPaintEvent *);
    void ubicacion();


private:
    Ui::Mapa *ui;
    QImage imMapa;
};

#endif // MAPA_H
