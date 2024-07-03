#ifndef HEALTH_H
#define HEALTH_H
#include<QGraphicsItem>

class Health: public QGraphicsTextItem
{


    private:
        int healthValue;

    public:
        Health(QGraphicsItem *h=0);
        void decrease();
        int getHealth();



};

#endif // HEALTH_H
