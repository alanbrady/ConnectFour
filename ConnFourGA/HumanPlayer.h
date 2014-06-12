#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "abstractplayer.h"
#include "gameboardwidget.h"

class HumanPlayer : public AbstractPlayer {
public:
    HumanPlayer(ConnectFourGame::PlayerColor color, GameboardWidget* widget)
        : AbstractPlayer(color), m_widget(widget)
    { }

    ~HumanPlayer() {}

    const int getPlayerMove(const GameBoard &board) { return -1; }
    bool isHuman() const { return true; }

private:
    GameboardWidget* m_widget;
};

#endif // HUMANPLAYER_H
