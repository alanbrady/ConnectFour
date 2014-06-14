#include "gaplayer.h"

GAPlayer::GAPlayer(char *chromosome)
{
}

int GAPlayer::getPlayerMove(const GameBoard &board)
{
   int bestMove = 0;
   double bestMoveScore = 0;

   if (isFirstMove()) {
       return m_firstMove%7;
   }

   for (int i = 0; i < 7; i++) {
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

}

bool GAPlayer::blocksDouble(int move)
{

}

bool GAPlayer::blocksTriple(int move)
{

}

bool GAPlayer::blocksQuad(int mvoe)
{

}

bool GAPlayer::makesDouble(int move)
{

}

bool GAPlayer::makesTriple(int move)
{

}

bool GAPlayer::makesQuad(int move)
{

}

bool GAPlayer::nextMoveMakesDouble(int move)
{

}

bool GAPlayer::nextMoveMakesTriple(int move)
{

}

bool GAPlayer::nextMoveMakesQuad(int move)
{

}

void GAPlayer::interpretChromosome()
{

}
