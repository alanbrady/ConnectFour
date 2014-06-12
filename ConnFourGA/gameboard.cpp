#include "gameboard.h"

GameBoard::GameBoard()
{
    qRegisterMetaType<GameBoard>("GameBoard");
    clearBoard();
}

void GameBoard::clearBoard()
{
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            m_rows[i][j] = 0;
        }
    }
}
