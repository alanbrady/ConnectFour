#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "abstractplayer.h"
#include "connectfourgame.h"

class HumanPlayer : public AbstractPlayer {
public:
    HumanPlayer(ConnectFourGame::PlayerColor color = ConnectFourGame::EMPTY)
        : AbstractPlayer(color)
    { }

    ~HumanPlayer() {}

    int getPlayerMove(const GameBoard&) { return -1; }
    bool isHuman() const { return true; }

private:
};

#endif // HUMANPLAYER_H
