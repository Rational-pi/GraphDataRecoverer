#ifndef GDRCONTROLLERBASE_H
#define GDRCONTROLLERBASE_H

#include <QObject>
#include "gdrmodelbase.h"

class GDRcontrollerBase : public QObject
{
    Q_OBJECT
private:
    GDRmodelBase *model;
public:
    explicit GDRcontrollerBase(QObject *parent = 0){}
    virtual bool loadFile(const QString &fileName)=0;
    virtual bool loadFromClipboard()=0;
    virtual void scaleContent(double factor)=0;
    virtual double getContentScale()=0;
signals:

public slots:

};

#endif // GDRCONTROLLERBASE_H
