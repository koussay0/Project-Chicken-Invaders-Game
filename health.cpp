#include "health.h"

#include<QGraphicsTextItem>
#include<QFont>
Health:: Health(QGraphicsItem *h) : QGraphicsTextItem(h){

    healthValue = 3;
    setPlainText(QString("Health : ")+QString::number(healthValue));
    setDefaultTextColor(QColorConstants::Red);
    setFont(QFont("times",16));


}

void Health::decrease(){
    healthValue--;
    setPlainText(QString("Health : ")+QString::number(healthValue));
}

int Health::getHealth()
{
    return healthValue;
}
