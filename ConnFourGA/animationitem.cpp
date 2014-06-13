#include "animationitem.h"

AnimationItem::AnimationItem(int move, const GameBoard &board, int color)
    : m_move(move), m_board(board), m_color(color), m_next(0)
{
}
