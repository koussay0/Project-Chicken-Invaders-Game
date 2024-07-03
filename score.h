#ifndef SCORE_H
#define SCORE_H

#include<QGraphicsItem>

class Score : public QGraphicsTextItem
{
private:
    int scoreValue;

public:
    Score(QGraphicsItem *s=0);
    void increase();
    int getScore();
};

#endif // SCORE_H
