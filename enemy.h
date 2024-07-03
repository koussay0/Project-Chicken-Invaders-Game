#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include<QMediaPlayer>
#include<QAudioOutput>
class Enemy: public QObject , public QGraphicsPixmapItem
{ Q_OBJECT
private:
    QMediaPlayer * bs;
    QAudioOutput * audio;


public:
    Enemy();
   static bool gameOverMessageShown;
public slots:
    void move();
};

#endif // ENEMY_H
