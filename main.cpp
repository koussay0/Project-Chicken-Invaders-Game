#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include "score.h"
#include"health.h"
#include<QMediaPlayer>
#include<QtMultimedia>
#include<QAudioOutput>

Score * score;
Health*health;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsView view;// *******  Create the View ********
    view.setFixedSize(800,600);
    QGraphicsScene scene;
    scene.setSceneRect(0,0,800,600);

    // ******* Create the Scene ********
    score= new Score;
    //core->setFont(QFont("times",16));
    //score->setDefaultTextColor(Qt::blue);
    //score->setPlainText(QString("Score:")+QString::number(0));
    score->setPos(700,10);
    scene.addItem(score);
    health=new Health;
    health->setPos(10,10);
    scene.addItem(health);
     Player*p=new Player();// *******  Create the Player ********

    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    // *******  Setting the foucs to the Player ********
    QPixmap pixmap1(":/Images/ship.png");
    p->setPixmap(pixmap1);
    p->setPos(view.width()/2,view.height()-pixmap1.height());
    scene.addItem(p);// *******  Adjust the location of the Player (middle of the screen) ********
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QMediaPlayer *Q = new QMediaPlayer;
    Q ->setSource(QUrl("qrc:/Aud/bgsound.mp3"));

   QAudioOutput *audio = new QAudioOutput;
    Q->setAudioOutput(audio);
   audio->setVolume(20);
   Q->play();


    view.setScene(&scene);
    view.show();// *******   Assign scene to the view   ***************


    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),p,SLOT(createEnemy()));
    time->start(2000);


    return a.exec();
}
