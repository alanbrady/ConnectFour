#ifndef MOCKPLAYER_H
#define MOCKPLAYER_H

#include "abstractplayer.h"

class MockPlayer : public AbstractPlayer
{
public:
    MockPlayer();

    int getPlayerMove(const GameBoard& board);

    bool isHuman() { return false; }
};

#endif // MOCKPLAYER_H
