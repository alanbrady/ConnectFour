#ifndef GAPLAYER_H
#define GAPLAYER_H

#include "abstractplayer.h"

class GAPlayer : public AbstractPlayer
{
public:
    GAPlayer(char* chromosome);

    int getPlayerMove(const GameBoard& board);
    bool isHuman() const { return false; }

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

    void interpretChromosome();
};

#endif // GAPLAYER_H
