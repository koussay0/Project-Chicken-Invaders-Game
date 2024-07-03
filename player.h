#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include<QMediaPlayer>

#include<QtMultimedia>

#include<QAudioOutput>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
public:

    void keyPressEvent(QKeyEvent * event);
private:
    QMediaPlayer * bs;
    QAudioOutput * audio;
    QGraphicsTextItem *score;
    QMediaPlayer* sound;
public slots:
    void createEnemy();

};

#endif // PLAYER_H
