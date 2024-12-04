#ifndef PIPE_H
#define PIPE_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "bird.h"
class pipe : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    bool istop;
    bool deleted = false;
public:
    pipe(bool istop, QGraphicsItem *parent = nullptr);
    void move();
    bool checkcollide(Bird* bird);
    bool isDeleted();
};

#endif // PIPE_H
