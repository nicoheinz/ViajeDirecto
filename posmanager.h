#ifndef POSMANAGER_H
#define POSMANAGER_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class PosManager : public QObject
{
    Q_OBJECT
public:
    PosManager();
    /**
     * @brief getLatLongGPS Devuelve la posicion que da el GPS
     * @return Un QStringList de solo 2 elementos con el primer elemento con la latitud y el segundo con la longitud.
     */
    QStringList getLatLongGPS() const;
    void setLatLongGPS(float ll, float lg);


    /**
     * @brief getDomicilioActual Devuleve el domicilio de donde esta este celular.
     * @return
     */
    void getDomicilioActual();
    void setDomicilioActual(QString dom);
    private:

        QString domicilio;
        float ll, lg;
        QNetworkAccessManager *manager;

    signals:
        /**
         * @brief signal_domicilioObtenido Se emitira desde el slot_solicitudFinalizada luego de haber analizado el XML o JSON, y
         * obtenido el domiciio. Esta signal podrá ser conectada desde otra clase, por ejemplo Ventana
         * @param domicilio
         */
        void signal_domicilioObtenido(QString domicilio);

    private slots:

        /**
         * @brief slot_solicitudFinalizada Slot que se conectara desde la signal finished(QNetworkReply*), el cual traera la respuesta
         * de Google en XML o JSON, la cual se debera analizar para obtener el domicilio
         */
        void slot_solicitudFinalizada(QNetworkReply *);
        /**
         * @brief pedirDomicilio Metodo que puede usarse desde otra clase, por ejemplo, Ventana, para que PosManager pida a Google
         * el domicilio correspondiente a la latitud y longitud. Dentro de este metodo se utilizara get de QNetworkAccessManager para
         * pedir a Google.
         * @param latitud
         * @param longitud
         */
        void pedirDomicilio(float latitud, float longitud);

};

#endif // POSMANAGER_H
