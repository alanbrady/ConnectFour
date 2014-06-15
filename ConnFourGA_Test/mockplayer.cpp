#include "mockplayer.h"

#include <cstdlib>

MockPlayer::MockPlayer()
    : AbstractPlayer(1)
{
}

int MockPlayer::getPlayerMove(const GameBoard &board)
{
    std::srand(0);
    return std::rand()%7;
}
