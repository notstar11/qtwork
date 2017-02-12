#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsItem>

class Snake :public QGraphicsItem
{
public:
       QRectF boundingRect() const;
       QPainterPath shape() const;
       void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
       void moveLeft();
       void moveRight();
       void moveUp();
       void moveDown();
       void handleCollisions();
       void advance(int step);

};

#endif // SNAKE_H
