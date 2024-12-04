#include "pipe.h"
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <qgraphicsscene.h>
#include "bird.h"

pipe::pipe(bool istop,QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent), istop(istop){
    if(istop)
    {
        setPixmap(QPixmap("C:/Users/tnanh/Downloads/T.png"));
    }
    else
    {
        setPixmap(QPixmap("C:/Users/tnanh/Downloads/P.png"));
    }
}

void pipe:: move(){
    setPos(x()-5,y());
    if(x()< -100){
        scene()->removeItem(this);
        this->deleted = true;
        delete this;
    }
}
bool pipe:: checkcollide(Bird* Bird)
{

}
bool pipe:: isDeleted(){
    return this->deleted;
}


