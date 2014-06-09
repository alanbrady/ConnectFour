#ifndef CONNECTFOURGAME_H
#define CONNECTFOURGAME_H

#include <stdlib.h>
#include <time.h>
#include "gameboard.h"
#include "abstractplayer.h"
#include "randomplayer.h"

class ConnectFourGame
{
public:
    ConnectFourGame();
    ConnectFourGame(AbstractPlayer* playerOne, AbstractPlayer* playerTwo);
    ConnectFourGame(const GameBoard& board);
    ~ConnectFourGame();

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
    PlayerColor getCurrentPlayerColor() const;
    bool makeMove(const int col, PlayerColor color);
    bool canMakeMove(const int col);

    void setPlayers(AbstractPlayer* playerOne, AbstractPlayer* playerTwo);
    void setPlayerOne(AbstractPlayer* playerOne);
    void setPlayerOneColor(PlayerColor color);
    void setPlayerTwo(AbstractPlayer* playerTwo);
    void setPlayerTwoColor(PlayerColor color);
    void swapPlayerColors();
    void randomlyAssignColors();
    void setFirstPlayer();

private:
    GameBoard m_board;
    AbstractPlayer* m_currentPlayer;
    AbstractPlayer* m_playerOne;
    AbstractPlayer* m_playerTwo;

};


#endif // CONNECTFOURGAME_H
