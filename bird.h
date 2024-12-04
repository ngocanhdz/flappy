#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bird : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    // Constructor
    Bird(QGraphicsItem *parent = nullptr);

    // jump when press space
    void jump();

    // decrease when jump and increase when not jump


    // va cham ong cong
    bool checkCollision();
public slots:
    void updatePosition();

private:
    float velocity;

    const float gravity = 0.5;
    const float jumpStrength = -8.0;

    void setBirdImage();
};

#endif // BIRD_H

