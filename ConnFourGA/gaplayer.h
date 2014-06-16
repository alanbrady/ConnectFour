#ifndef GAPLAYER_H
#define GAPLAYER_H

#include "connectfourgame.h"
#include "abstractplayer.h"

class GAPlayer : public AbstractPlayer
{
public:
    GAPlayer(char* chromosome);

    int getPlayerMove(const GameBoard& board);

    double getBlockDouble() const { return m_blockDouble; }
    double getBlockTriple() const { return m_blockTriple; }
    double getBlockQuad() const { return m_blockQuad; }
    double getMakesDouble() const { return m_makeDouble; }
    double getMakesTriple() const { return m_makeTriple; }
    double getMakesQuad() const { return m_makeQuad; }
    double getNextMoveDouble() const { return m_nextMoveDouble; }
    double getNextMoveTriple() const { return m_nextMoveTriple; }
    double getNextMoveQuad() const { return m_nextMoveQuad; }
    int getFirstMove() const { return m_firstMove; }

    bool isFirstMove() const;
    bool isValidMove(int move) const;
    int blocksDouble(int move);
    int blocksTriple(int move);
    int blocksQuad(int mvoe);
    int makesDouble(int move);
    int makesTriple(int move);
    int makesQuad(int move);
    int nextMoveMakesDouble(int move);
    int nextMoveMakesTriple(int move);
    int nextMoveMakesQuad(int move);

private:
    char* m_chromosome;
    double m_blockDouble;
    double m_blockTriple;
    double m_blockQuad;
    double m_makeDouble;
    double m_makeTriple;
    double m_makeQuad;
    double m_nextMoveDouble;
    double m_nextMoveTriple;
    double m_nextMoveQuad;
    int m_firstMove;

    GameBoard m_board;

    void interpretChromosome();
    int getBottomRow(int col);
    ConnectFourGame::PlayerColor getOpponentColor();
};

#endif // GAPLAYER_H
