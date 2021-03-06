#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H

#include "gameboard.h"

class AbstractPlayer {
public:
    AbstractPlayer(int color)
        {
            m_color = color;
        }
    AbstractPlayer() { m_color = 0; }
    virtual ~AbstractPlayer() {}

    int getColor() const { return m_color; }
    void setPlayerColor(int color) { m_color = color; }

    virtual int getPlayerMove(const GameBoard& board) = 0;
    virtual bool isHuman() const { return false; }
    virtual void badMoveMade() {}

private:
    int m_color;
};

#endif // ABSTRACTPLAYER_H
