#ifndef GDRMODELBASE_H
#define GDRMODELBASE_H

#include <QObject>

class GDRmodelBase : public QObject
{
    Q_OBJECT
private:
    double drawingScaleFactor;
public:
    explicit GDRmodelBase(QObject *parent = 0);

signals:

public slots:
};

#endif // GDRMODELBASE_H
