#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "abstractplayer.h"

class HumanPlayer : public AbstractPlayer {
public:
    HumanPlayer(ConnectFourGame::PlayerColor color)
        : AbstractPlayer(color)
    { }

    ~HumanPlayer() {}

    const int getPlayerMove(const GameBoard &board) { return -1; }
    bool isHuman() const { return true; }
};

#endif // HUMANPLAYER_H
