#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include <stdlib.h>
#include <time.h>
#include "abstractplayer.h"

class RandomPlayer : public AbstractPlayer
{
public:
    RandomPlayer();

    bool isHuman() const { return false; }
    int getPlayerMove(const GameBoard &);
};

#endif // RANDOMPLAYER_H
