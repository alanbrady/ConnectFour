#include "connectfourgame.h"

ConnectFourGame::ConnectFourGame()
{
    m_playerOne = new RandomPlayer();
    m_playerTwo = new RandomPlayer();
    randomlyAssignColors();
    setFirstPlayer();
}

ConnectFourGame::ConnectFourGame(AbstractPlayer *playerOne, AbstractPlayer *playerTwo)
{
    m_playerOne = playerOne;
    m_playerTwo = playerTwo;
    randomlyAssignColors();
    setFirstPlayer();
}

ConnectFourGame::ConnectFourGame(const GameBoard &board)
{
    m_board = board;
    m_playerOne = new RandomPlayer();
    m_playerTwo = new RandomPlayer();
    randomlyAssignColors();
    setFirstPlayer();
}

ConnectFourGame::~ConnectFourGame()
{
    if (m_playerOne != 0)
        delete m_playerOne;
    if (m_playerTwo != 0)
        delete m_playerTwo;
}

ConnectFourGame::PlayerColor ConnectFourGame::getColorAt(const int row, const int col)
{
    return ConnectFourGame::PlayerColor(m_board[row][col]);
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

ConnectFourGame::PlayerColor ConnectFourGame::getCurrentPlayerColor() const
{
     return PlayerColor(m_currentPlayer->getColor());
}

bool ConnectFourGame::makeMove(const int col, ConnectFourGame::PlayerColor color)
{

    if (canMakeMove(col)) {
        int i = 0;
        while (m_board[i][col] != 0)
            i++;
        m_board[i][col] = color;
        return true;
    } else
        return false;
}

bool ConnectFourGame::canMakeMove(const int col)
{
    return m_board[5][col] == 0 && col >= 0 && col <= 6;
}

void ConnectFourGame::setPlayers(AbstractPlayer *playerOne, AbstractPlayer *playerTwo)
{
    if (m_playerOne != 0)
        delete m_playerOne;
    if (m_playerTwo != 0)
        delete m_playerTwo;
    m_playerOne = playerOne;
    m_playerTwo = playerTwo;
    randomlyAssignColors();
    setFirstPlayer();
}

void ConnectFourGame::setPlayerOne(AbstractPlayer *playerOne)
{
    if (m_playerOne != 0)
        delete m_playerOne;
    m_playerOne = playerOne;
}

void ConnectFourGame::setPlayerOneColor(ConnectFourGame::PlayerColor color)
{
    if (m_playerOne != 0)
        m_playerOne->setPlayerColor(color);
    setFirstPlayer();
}

void ConnectFourGame::setPlayerTwo(AbstractPlayer *playerTwo)
{
    if (m_playerTwo != 0)
        delete m_playerTwo;
    m_playerTwo = playerTwo;
}

void ConnectFourGame::setPlayerTwoColor(ConnectFourGame::PlayerColor color)
{
    if (m_playerTwo != 0)
        m_playerTwo->setPlayerColor(color);
    setFirstPlayer();
}

void ConnectFourGame::swapPlayerColors()
{
    PlayerColor color = PlayerColor(m_playerOne->getColor());
    m_playerOne->setPlayerColor(m_playerTwo->getColor());
    m_playerTwo->setPlayerColor(color);
    setFirstPlayer();
}

void ConnectFourGame::randomlyAssignColors()
{
    srand(time(NULL));
    int randInt = rand()%2;
    if (randInt == 0) {
        m_playerOne->setPlayerColor(BLACK);
        m_playerTwo->setPlayerColor(RED);
    } else {
        m_playerOne->setPlayerColor(RED);
        m_playerTwo->setPlayerColor(BLACK);
    }
}

void ConnectFourGame::setFirstPlayer()
{
    if (m_playerOne->getColor() == BLACK)
        m_currentPlayer = m_playerOne;
    else
        m_currentPlayer = m_playerTwo;
}

void ConnectFourGame::startGame()
{
    if (m_playerOne != 0 && m_playerTwo != 0) {
        if (m_playerOne->getColor() != EMPTY &&
                m_playerTwo->getColor() != EMPTY) {
            m_board.clearBoard();
            do {
                int move = -1;
                do {
                    move = m_currentPlayer->getPlayerMove();
                } while(!canMakeMove(move));
                makeMove(move, m_currentPlayer->getColor());
                swapCurrentPlayer();
            } while (!checkForWin());
        } else emit error("Error: player colors not set");
    } else emit error("Error: Players not initialized");
}

void ConnectFourGame::swapCurrentPlayer()
{
    if (m_currentPlayer == m_playerOne)
        m_currentPlayer = m_playerTwo;
    else
        m_currentPlayer = m_playerOne;
}
