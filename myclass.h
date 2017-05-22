#ifndef MYCLASS_H
#define MYCLASS_H

#include <QGeoPositionInfoSource>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT
public:
    MyClass(QObject *parent = 0)
        : QObject(parent)
    {
        QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
        if (source) {
            connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                    this, SLOT(positionUpdated(QGeoPositionInfo)));
            source->startUpdates();
        }
    }

    float alt;
    float lon;

    double getAltitud()
    {
        return alt;
    }

    double getLongitud()
    {
        return lon;
    }

private slots:
    void positionUpdated(const QGeoPositionInfo &info)
    {
       qDebug()<< info.coordinate().latitude();
       qDebug()<< info.coordinate().longitude();

//       alt=info.coordinate().altitude();
//       lon=info.coordinate().longitude();

       alt = -31.4207166;
       lon = -64.1833505;
    }
};

#endif // MYCLASS_H
