#ifndef MAPAS_H
#define MAPAS_H
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>

#include <QWidget>

class Mapas : public QWidget
{
    Q_OBJECT
    QImage im;

    void paintEvent(QPaintEvent *);

public:

    explicit Mapas(QWidget *parent = 0);
    void setMapa(QImage im);
signals:

public slots:
};

#endif // MAPAS_H
