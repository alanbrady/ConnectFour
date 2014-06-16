#include "gaplayer.h"

GAPlayer::GAPlayer(char *chromosome)
    : m_chromosome(chromosome) {
    interpretChromosome();
}

int GAPlayer::getPlayerMove(const GameBoard &board)
{
   int bestMove = 0;
   double bestMoveScore = 0;
   m_board = board;

   if (isFirstMove()) {
       return m_firstMove%7;
   }

   for (int i = 0; i < 7; i++) {
       if (!isValidMove(i)) continue;

       double score = m_blockDouble*blocksDouble(i) +
               m_blockTriple*blocksTriple(i) +
               m_blockQuad*blocksQuad(i) +
               m_makeDouble*makesDouble(i) +
               m_makeTriple*makesTriple(i) +
               m_makeQuad*makesQuad(i) +
               m_nextMoveDouble*nextMoveMakesDouble(i) +
               m_nextMoveTriple*nextMoveMakesTriple(i) +
               m_nextMoveQuad*nextMoveMakesQuad(i);
       if (score > bestMoveScore) {
           bestMoveScore = score;
           bestMove = i;
       }
   }
   return bestMove;
}

bool GAPlayer::isFirstMove() const
{
    GameBoardRow bottomRow = m_board[0];
    for (int i = 0; i < 7; i++) {
        if (bottomRow[i] != ConnectFourGame::EMPTY) {
            return false;
        }
    }
    return true;
}

bool GAPlayer::isValidMove(int move) const
{
    return move >= 0 && move <= 6 && m_board[5][move] == 0;
}

int GAPlayer::blocksDouble(int move)
{
    int bottomRow = getBottomRow(move);
    int numDoubles = 0;
    ConnectFourGame::PlayerColor opponentColor = getOpponentColor();

    if (move > 0) {
        if (bottomRow < 5) {
            if (m_board[bottomRow+1][move-1] == opponentColor)
                numDoubles++;
        }
        if (bottomRow > 0) {
            if (m_board[bottomRow-1][move-1] == opponentColor)
                numDoubles++;
        }
        if (m_board[bottomRow][move-1] == opponentColor)
            numDoubles++;
    }

    if (move < 6) {
        if (bottomRow < 5) {
            if (m_board[bottomRow+1][move+1] == opponentColor)
                numDoubles++;
        }
        if (bottomRow > 0) {
            if (m_board[bottomRow-1][move+1] == opponentColor)
                numDoubles++;
        }
        if (m_board[bottomRow][move+1] == opponentColor)
            numDoubles++;
    }

    if (bottomRow > 0) {
        if (m_board[bottomRow-1][move] == opponentColor)
            numDoubles++;
    }

    return numDoubles;
}

int GAPlayer::blocksTriple(int move)
{
    int bottomRow = getBottomRow(move);
    int numTriples = 0;
    ConnectFourGame::PlayerColor opponentColor = getOpponentColor();

    if (move > 1) {
        if (bottomRow < 4) {
            if (m_board[bottomRow+1][move-1] == opponentColor &&
                    m_board[bottomRow+2][move-2] == opponentColor)
                numTriples++;
        }
        if (bottomRow > 1) {
            if (m_board[bottomRow-1][move-1] == opponentColor &&
                    m_board[bottomRow-2][move-2] == opponentColor)
                numTriples++;
        }
        if (m_board[bottomRow][move-1] == opponentColor &&
                m_board[bottomRow][move-2] == opponentColor)
            numTriples++;
    }

    if (move < 5) {
        if (bottomRow < 4) {
            if (m_board[bottomRow+1][move+1] == opponentColor &&
                    m_board[bottomRow+2][move+2] == opponentColor)
                numTriples++;
        }
        if (bottomRow > 1) {
            if (m_board[bottomRow-1][move+1] == opponentColor &&
                    m_board[bottomRow-2][move+2] == opponentColor)
                numTriples++;
        }
        if (m_board[bottomRow][move+1] == opponentColor &&
                m_board[bottomRow][move+2] == opponentColor)
            numTriples++;
    }

    if (bottomRow > 1)
        if (m_board[bottomRow-1][move] == opponentColor &&
                m_board[bottomRow-2][move] == opponentColor)
            numTriples++;

    if (move > 0 && move < 6) {
        if (bottomRow > 0 && bottomRow < 5) {
            if (m_board[bottomRow+1][move-1] == opponentColor &&
                    m_board[bottomRow-1][move+1] == opponentColor)
                numTriples++;
            if (m_board[bottomRow+1][move+1] == opponentColor &&
                    m_board[bottomRow-1][move-1] == opponentColor)
                numTriples++;
        }
        if (m_board[bottomRow][move-1] == opponentColor &&
                m_board[bottomRow][move+1] == opponentColor)
            numTriples++;
    }
    return numTriples;
}

int GAPlayer::blocksQuad(int move)
{
    int bottomRow = getBottomRow(move);
    int numQuads = 0;
    ConnectFourGame::PlayerColor opponentColor = getOpponentColor();

    if (move < 4) {
        if (m_board[bottomRow][move+1] == opponentColor &&
                m_board[bottomRow][move+2] == opponentColor &&
                m_board[bottomRow][move+3] == opponentColor)
            numQuads++;
        if (bottomRow < 3)
            if (m_board[bottomRow+1][move+1] == opponentColor &&
                    m_board[bottomRow+2][move+2] == opponentColor &&
                    m_board[bottomRow+3][move+3] == opponentColor)
                numQuads++;
        if (bottomRow > 2)
            if (m_board[bottomRow-1][move+1] == opponentColor &&
                    m_board[bottomRow-2][move+2] == opponentColor &&
                    m_board[bottomRow-3][move+3] == opponentColor)
                numQuads++;
    }

    if (move > 2) {
        if (m_board[bottomRow][move-1] == opponentColor &&
                m_board[bottomRow][move-2] == opponentColor &&
                m_board[bottomRow][move-3] == opponentColor)
            numQuads++;
        if (bottomRow < 3)
            if (m_board[bottomRow+1][move-1] == opponentColor &&
                    m_board[bottomRow+2][move-2] == opponentColor &&
                    m_board[bottomRow+3][move-3] == opponentColor)
                numQuads++;
        if (bottomRow > 2)
            if (m_board[bottomRow-1][move-1] == opponentColor &&
                    m_board[bottomRow-2][move-2] == opponentColor &&
                    m_board[bottomRow-3][move-3] == opponentColor)
                numQuads++;
    }
    if (bottomRow > 2) {
        if (m_board[bottomRow-1][move] == opponentColor &&
                m_board[bottomRow-2][move] == opponentColor &&
                m_board[bottomRow-3][move] == opponentColor)
            numQuads++;
    }

    return numQuads;
}

int GAPlayer::makesDouble(int move)
{
    ConnectFourGame::PlayerColor color = getColor();
    int numDoubles = 0;
    int bottomRow = getBottomRow(move);

    if (move > 0) {
        if (bottomRow < 5) {
            if (m_board[bottomRow+1][move-1] == color)
                numDoubles++;
        }
        if (bottomRow > 0) {
            if (m_board[bottomRow-1][move-1] == color)
                numDoubles++;
        }
        if (m_board[bottomRow][move-1] == color)
            numDoubles++;
    }
    if (move < 6) {
        if (bottomRow < 5) {
            if (m_board[bottomRow+1][move+1] == color)
                numDoubles++;
        }
        if (bottomRow > 0) {
            if (m_board[bottomRow-1][move+1] == color)
                numDoubles++;
        }
        if (m_board[bottomRow][move+1] == color)
            numDoubles++;
    }

    if (bottomRow > 0) {
        if (m_board[bottomRow-1][move] == color)
            numDoubles++;
    }

    return numDoubles;
}

int GAPlayer::makesTriple(int move)
{
    int bottomRow = getBottomRow(move);
    int numTriples = 0;
    ConnectFourGame::PlayerColor color = getColor();

    if (move > 1) {
        if (bottomRow < 4) {
            if (m_board[bottomRow+1][move-1] == color &&
                    m_board[bottomRow+2][move-2] == color)
                numTriples++;
        }
        if (bottomRow > 1) {
            if (m_board[bottomRow-1][move-1] == color &&
                    m_board[bottomRow-2][move-2] == color)
                numTriples++;
        }
        if (m_board[bottomRow][move-1] == color &&
                m_board[bottomRow][move-2] == color)
            numTriples++;
    }

    if (move < 5) {
        if (bottomRow < 4) {
            if (m_board[bottomRow+1][move+1] == color &&
                    m_board[bottomRow+2][move+2] == color)
                numTriples++;
        }
        if (bottomRow > 1) {
            if (m_board[bottomRow-1][move+1] == color &&
                    m_board[bottomRow-2][move+2] == color)
                numTriples++;
        }
        if (m_board[bottomRow][move+1] == color &&
                m_board[bottomRow][move+2] == color)
            numTriples++;
    }

    if (bottomRow > 1)
        if (m_board[bottomRow-1][move] == color &&
                m_board[bottomRow-2][move] == color)
            numTriples++;

    if (move > 0 && move < 6) {
        if (bottomRow > 0 && bottomRow < 5) {
            if (m_board[bottomRow+1][move-1] == color &&
                    m_board[bottomRow-1][move+1] == color)
                numTriples++;
            if (m_board[bottomRow+1][move+1] == color &&
                    m_board[bottomRow-1][move-1] == color)
                numTriples++;
        }
        if (m_board[bottomRow][move-1] == color &&
                m_board[bottomRow][move+1] == color)
            numTriples++;
    }
    return numTriples;
}

int GAPlayer::makesQuad(int move)
{
    // TODO
    return false;
}

int GAPlayer::nextMoveMakesDouble(int move)
{
    // TODO
    return false;
}

int GAPlayer::nextMoveMakesTriple(int move)
{
    // TODO
    return false;
}

int GAPlayer::nextMoveMakesQuad(int move)
{
    // TODO
    return false;
}

void GAPlayer::interpretChromosome()
{
    char* iter = m_chromosome;
    m_blockDouble = *((double*)(iter));
    iter += sizeof(double);
    m_blockTriple = *((double*)(iter));
    iter += sizeof(double);
    m_blockQuad =  *((double*)(iter));
    iter += sizeof(double);
    m_makeDouble =  *((double*)(iter));
    iter += sizeof(double);
    m_makeTriple =  *((double*)(iter));
    iter += sizeof(double);
    m_makeQuad =  *((double*)(iter));
    iter += sizeof(double);;
    m_nextMoveDouble =  *((double*)(iter));
    iter += sizeof(double);;
    m_nextMoveTriple =  *((double*)(iter));
    iter += sizeof(double);;
    m_nextMoveQuad =  *((double*)(iter));
    iter += sizeof(double);;
    m_firstMove = (int)(*iter & 0xFF);

}

int GAPlayer::getBottomRow(int col)
{
    for (int row = 0; row < 6; row++) {
        if (m_board[row][col] == ConnectFourGame::EMPTY)
            return row;
    }
    return -1;
}

ConnectFourGame::PlayerColor GAPlayer::getOpponentColor()
{
    if (getColor() == ConnectFourGame::BLACK)
        return ConnectFourGame::RED;
    else
        return ConnectFourGame::BLACK;
}
