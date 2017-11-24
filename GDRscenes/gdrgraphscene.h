#ifndef GDRGRAPHSCENE_H
#define GDRGRAPHSCENE_H
#include "gdrscenebase.h"
#include <QString>

class GDRGraphScene : public GDRsceneBase
{
public:
    GDRGraphScene(QObject *parent = Q_NULLPTR):GDRsceneBase(parent){}
    GDRGraphScene(const QImage &image, const QString &name="", QObject *parent = Q_NULLPTR):GDRsceneBase(name,parent){
        addPixmap(QPixmap::fromImage(image));
    }

};

#endif // GDRGRAPHSCENE_H
