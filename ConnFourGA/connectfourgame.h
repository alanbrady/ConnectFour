#ifndef CONNECTFOURGAME_H
#define CONNECTFOURGAME_H

#include "gameboard.h"

class ConnectFourGame
{
public:
    ConnectFourGame();
    ConnectFourGame(const GameBoard& board);

    enum PlayerColor {
        BLACK = 1,
        RED = -1,
        EMPTY = 0,
    };

    void setBoard(const GameBoard& board) { m_board = board; }
    const GameBoard& getBoard() const { return m_board; }

    bool checkForWin() const;
    int countConnsRight(const int row, const int col) const;
    int countConnsDiagRight(const int row, const int col) const;
    int countConnsDiagLeft(const int row, const int col) const;
    int countConnsVertical(const int row, const int col) const;

    bool makeMove(const int col, PlayerColor color);
private:
    GameBoard m_board;

};


#endif // CONNECTFOURGAME_H
