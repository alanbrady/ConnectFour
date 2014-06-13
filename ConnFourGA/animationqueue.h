#ifndef ANIMATIONQUEUE_H
#define ANIMATIONQUEUE_H

#include "gameboard.h"
#include "animationitem.h"

#define INIT_SIZE 20

class AnimationQueue
{
public:
    AnimationQueue();
    ~AnimationQueue();

    void add(int move, const GameBoard& board, int color);
    AnimationItem *next();

private:
    AnimationItem* m_head;
    AnimationItem* m_last;

};

#endif // ANIMATIONQUEUE_H
