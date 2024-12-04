#include "bird.h"
#include <QTimer>
#include<QGraphicsScene>
Bird::Bird(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), velocity(0) // khoi tao lop cha trước lớp con
{
    setBirdImage();// phuong thuc bird
    setPos(640, 360);   // phuong thuc ke thua tu QGraphItem
    setScale(0.1);
}

void Bird::jump()
{
    velocity = jumpStrength; // van toc nhay len >0 thi roi xuong <0 thi bay len
}

void Bird::updatePosition()
{
    velocity += gravity;
    setY(y()+velocity);
    if (scene() != nullptr) {
        if (y() > scene()->height() || y() < 0) {
            setY(300); // Đưa chim về vị trí ban đầu
            velocity = 0; // Reset vận tốc
        }
    }
}

void Bird::setBirdImage()
{
    QPixmap pixmap("C:/Users/tnanh/Downloads/pngegg.png");
    if (pixmap.isNull()) {
        qDebug() << "Failed to load image!";
    }
    setPixmap(pixmap);
}
