#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H

#endif // ABSTRACTPLAYER_H

#include "gameboard.h"
#include "connectfourgame.h"

class AbstractPlayer {
public:
    AbstractPlayer(ConnectFourGame::PlayerColor color)
        {
            m_color = color;
        }
    virtual ~AbstractPlayer() {}

    ConnectFourGame::PlayerColor getColor() { return m_color; }


    virtual int getPlayerMove(const GameBoard& board) = 0;
    virtual bool isHuman() const = 0;

private:
    ConnectFourGame::PlayerColor m_color;
};
