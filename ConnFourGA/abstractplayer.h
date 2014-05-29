#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H

#endif // ABSTRACTPLAYER_H

#include "gameboard.h"
#include "connectfourgame.h"

class AbstractPlayer {
public:
    AbstractPlayer(GameBoard* board,
                   ConnectFourGame::PlayerColor color)
        {
            m_board = board;
            m_color = color;
        }
    virtual ~AbstractPlayer() {}

    ConnectFourGame::PlayerColor getColor() { return m_color; }

    virtual int getPlayerMove() = 0;
    virtual bool isHuman() = 0;

private:
    GameBoard *m_board;
    ConnectFourGame::PlayerColor m_color;
};
