#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include "score.h"



extern Score* score;
Bullet::Bullet():QObject(), QGraphicsPixmapItem() {

    // *******  Setting the bullets' size ********
QPixmap pixmap2(":/Images/red_laser.png");
    setPixmap(pixmap2);

    // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    bs = new QMediaPlayer();
    bs->setSource(QUrl("qrc:/Aud/destruction.m4a"));
    audio = new QAudioOutput;
    bs->setAudioOutput(audio);



}

// Move function is used to 1-  move the bullet upwards
// 2- Handle the collision of the bullets with enemies
void Bullet:: move()
{
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0;i<colliding_items.size();i++)
    {
        if(typeid(*(colliding_items[i]))==typeid(Enemy))
        {
            score->increase();
           scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            audio->setVolume(50);
            bs->play();
            delete this;
        }
    }

    setPos(x(),y()-10);
    if(pos().y()<0)
    {
        scene()->removeItem(this);
        delete this;
    }

    // *******  Getting the colliding items with the Bullet ********


    // *******  Moving the bullets upward ********

}
