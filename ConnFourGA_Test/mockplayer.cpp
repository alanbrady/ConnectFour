#include "mockplayer.h"

#include <cstdlib>

MockPlayer::MockPlayer(GameBoard *board)
    : AbstractPlayer(board, ConnectFourGame::BLACK)
{
}

int MockPlayer::getPlayerMove()
{
    std::srand(0);
    return std::rand()%7;
}
