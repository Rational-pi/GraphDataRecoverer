#ifndef GDRSCENEBASE_H
#define GDRSCENEBASE_H
#include <QGraphicsScene>

class GDRsceneBase : public QGraphicsScene
{
public:
    GDRsceneBase(QObject *parent = Q_NULLPTR);

    GDRsceneBase(const QString &name="", QObject *parent = Q_NULLPTR):QGraphicsScene(parent),name(name){}

    QString getName(){return name;}
private:
    QString name;
};

#endif // GDRSCENEBASE_H
