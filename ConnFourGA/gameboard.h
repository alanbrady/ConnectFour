#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>
#include "gameboardrow.h"

class GameBoard
{
public:
    GameBoard();

    GameBoardRow& operator[](int i) { return m_rows[i]; }
    const GameBoardRow& operator[](int i) const { return m_rows[i]; }

    void clearBoard();
    int getRowCount() const { return 6; }
    int getColCount() const { return 7; }

private:
    GameBoardRow m_rows[6];

};

Q_DECLARE_METATYPE(GameBoard)

#endif // GAMEBOARD_H
