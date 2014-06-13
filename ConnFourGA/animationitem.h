#ifndef ANIMATIONITEM_H
#define ANIMATIONITEM_H

#include "gameboard.h"

class AnimationItem
{
public:
    AnimationItem(int move, const GameBoard& board, int color);

    GameBoard getBoard() const { return m_board; }
    int getColor() const { return m_color; }
    int getMove() const { return m_move; }
    void setNext(AnimationItem* next) { m_next = next; }
    AnimationItem* getNext() { return m_next; }

private:
    int m_move;
    const GameBoard m_board;
    const int m_color;
    AnimationItem* m_next;
};

#endif // ANIMATIONITEM_H
