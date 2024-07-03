#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include<QMediaPlayer>
#include<QAudioOutput>
class Bullet: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
private:
    QMediaPlayer*bs = new QMediaPlayer;
    QAudioOutput * audio = new QAudioOutput;


public:
    Bullet();

public slots:
    void move();
};

#endif // BULLET_H
