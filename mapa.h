#ifndef MAPA_H
#define MAPA_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace Ui{
class Mapa;
}
class Mapa : public QWidget
{
    Q_OBJECT
    QImage im;



public:

    explicit Mapa(QWidget *parent = 0);
    void setMapa(QImage im);

    /**
     * @brief getMapa Metodo que recibe la url completa con el dsomicilio y todo.
     * Este metodo puede emitir una senal que envie el QImage
     * @param url
     */
    void getMapa(QUrl url);
private:
    Ui::Mapa *ui;
    QNetworkAccessManager *ManagerMapa;
    QImage imMapa;
protected:
        void paintEvent(QPaintEvent *);

private slots:
        void slot_procesarRespuesta(QNetworkReply * reply);
        void slot_dibuja();

signals:
        signal_mapa();
};

#endif // MAPA_H
