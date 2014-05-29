#ifndef MOCKPLAYER_H
#define MOCKPLAYER_H

#include "abstractplayer.h"

class MockPlayer : public AbstractPlayer
{
public:
    MockPlayer(GameBoard* board);

    int getPlayerMove();

    bool isHuman() { return false; }
};

#endif // MOCKPLAYER_H
