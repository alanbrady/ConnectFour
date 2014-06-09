#include "randomplayer.h"

RandomPlayer::RandomPlayer()
{
    srand(time(NULL));
}

int RandomPlayer::getPlayerMove(const GameBoard &)
{
    return rand()%7;
}
