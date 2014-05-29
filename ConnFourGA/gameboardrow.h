#ifndef GAMEBOARDROW_H
#define GAMEBOARDROW_H

class GameBoardRow
{
public:
    GameBoardRow();

    int& operator[](int i) { return m_columns[i]; }
    int operator[](int i) const { return m_columns[i]; }

private:
    int m_columns[7];
};

#endif // GAMEBOARDROW_H
