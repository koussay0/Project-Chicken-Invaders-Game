#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include<QMessageBox>
#include"health.h"
#include"score.h"
#include <QMainWindow>
extern Health *health;
extern Score* score;
 bool Enemy::gameOverMessageShown = false;
Enemy::Enemy():QObject(), QGraphicsPixmapItem() {

    QPixmap pixmap3(":/Images/enemy.jpeg");
    pixmap3.scaled(100,100);
    setPixmap(pixmap3);
    // *******  Setting the size of the enemy ********


    // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() %(800- pixmap3.width());
    setPos(random_number,0);

    // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    bs = new QMediaPlayer();
    bs->setSource(QUrl("qrc:/Aud/GameOver.wav"));
    audio = new QAudioOutput;
    bs->setAudioOutput(audio);


}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{

    setPos(x(),y()+5);
    if(y()+100>800)
    {

        if(health->getHealth()<2)
        {

            if (!gameOverMessageShown)
            {
                health->decrease();
                // Show QMessageBox
                QMessageBox* msg = new QMessageBox;
                msg->setText(QString("You have LOST and your score is : ") + QString::number(score->getScore()));
                msg->setWindowTitle(QString("End Game"));
                audio->setVolume(50);
                bs->play();
                msg->show();


                // Set the flag to true to indicate that the message has been shown
                gameOverMessageShown = true;
            }

        }
        else
        {
            health->decrease();
        }
        scene()->removeItem(this);

        delete this;

    }
}
