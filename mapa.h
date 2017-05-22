#ifndef MAPA_H
#define MAPA_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

namespace Ui{
class Mapa;
}
class Mapa : public QWidget
{
    Q_OBJECT
    QImage im;

    void paintEvent(QPaintEvent *);

public:

    explicit Mapa(QWidget *parent = 0);
    void setMapa(QImage im);

private:
    Ui::Mapa *ui;
};

#endif // MAPA_H
