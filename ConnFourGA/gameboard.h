#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "gameboardrow.h"

class GameBoard
{
public:
    GameBoard();

    GameBoardRow& operator[](int i) { return m_rows[i]; }
    const GameBoardRow& operator[](int i) const { return m_rows[i]; }

    void clearBoard();

private:
    GameBoardRow m_rows[6];

};

#endif // GAMEBOARD_H
