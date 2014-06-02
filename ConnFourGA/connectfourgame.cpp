#include "connectfourgame.h"

ConnectFourGame::ConnectFourGame()
{
    m_currentPlayer = BLACK;
}

ConnectFourGame::ConnectFourGame(const GameBoard &board)
{
    m_board = board;
    m_currentPlayer = BLACK;
}

bool ConnectFourGame::checkForWin() const
{
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 7; col++) {
            if (m_board[row][col] != 0) {
                if (col < 4) {
                    if (countConnsRight(row, col) >= 4)
                        return true;

                    if (row < 3) {
                        if (countConnsDiagRight(row, col) >= 4)
                            return true;
                    }

                }
                if (col > 2 && row < 3)
                    if (countConnsDiagLeft(row, col) >= 4)
                        return true;

                if (row < 4)
                    if (countConnsVertical(row, col) >= 4)
                        return true;
            }
        }
    }
    return false;
}

int ConnectFourGame::countConnsRight(const int row, const int col) const
{
    if (col < 6 && m_board[row][col+1] ==  m_board[row][col])
        return 1+countConnsRight(row, col+1);
    else
        return 1;
}

int ConnectFourGame::countConnsDiagRight(const int row, const int col) const
{
    ;
    if (row < 5 && col < 6 && m_board[row+1][col+1] == m_board[row][col])
        return 1+countConnsDiagRight(row+1, col+1);
    else
        return 1;
}

int ConnectFourGame::countConnsDiagLeft(const int row, const int col) const
{
    if (row < 5 && col > 0 && m_board[row+1][col-1] == m_board[row][col])
        return 1+countConnsDiagLeft(row+1, col-1);
    else
        return 1;
}

int ConnectFourGame::countConnsVertical(const int row, const int col) const
{
    if (row < 5 && m_board[row+1][col] == m_board[row][col])
        return 1+countConnsVertical(row+1, col);
    else
        return 1;
}

bool ConnectFourGame::makeMove(const int col, ConnectFourGame::PlayerColor color)
{

    if (m_board[col][5] == 0 && col >= 0 && col <= 6) {
        int i = 0;
        while (m_board[col][i] != 0)
            i++;
        m_board[col][i] = color;
        return true;
    } else
        return false;
}
