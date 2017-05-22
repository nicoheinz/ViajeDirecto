#ifndef MAPA_H
#define MAPA_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>


class Mapa : public QWidget
{
    Q_OBJECT

    QImage im;

    void paintEvent(QPaintEvent *);

public:

    void setMapa(QImage im);

    Mapa();

private slots:


};

#endif // MAPA_H
