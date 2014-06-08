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

public:
    void setBoard(const GameBoard& board) { m_board = board; }
    const GameBoard& getBoard() const { return m_board; }

    ConnectFourGame::PlayerColor getColorAt(const int row, const int col);
    bool checkForWin() const;
    int countConnsRight(const int row, const int col) const;
    int countConnsDiagRight(const int row, const int col) const;
    int countConnsDiagLeft(const int row, const int col) const;
    int countConnsVertical(const int row, const int col) const;
    PlayerColor getCurrentPlayer() const { return m_currentPlayer; }

    bool makeMove(const int col, PlayerColor color);
    bool canMakeMove(const int col);

private:
    GameBoard m_board;
    PlayerColor m_currentPlayer;
};


#endif // CONNECTFOURGAME_H
