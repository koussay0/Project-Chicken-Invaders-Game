#include "score.h"
#include<QGraphicsTextItem>
#include<QFont>
Score:: Score(QGraphicsItem *s) : QGraphicsTextItem(s){

    scoreValue = 0;
    setPlainText(QString("score : ")+QString::number(scoreValue));
    setDefaultTextColor(QColorConstants::Blue);
    setFont(QFont("times",16));


}

void Score::increase(){
    scoreValue++;
     setPlainText(QString("score : ")+QString::number(scoreValue));
}

int Score::getScore()
{
    return scoreValue;
}
