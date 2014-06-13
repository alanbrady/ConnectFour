#include "animationqueue.h"

AnimationQueue::AnimationQueue()
{
    m_head = 0;
    m_last = 0;
}

AnimationQueue::~AnimationQueue()
{
    while (m_head != 0) {
        AnimationItem* next = m_head->getNext();
        delete m_head;
        m_head = next;
    }
}

void AnimationQueue::add(int move, const GameBoard &board, int color)
{
    AnimationItem* newItem = new AnimationItem(move, board, color);
    if (m_last == 0) {
        m_last = newItem;
        m_head = newItem;
    } else {
        m_last->setNext(newItem);
        m_last = newItem;
    }
}

AnimationItem* AnimationQueue::next()
{
    if (m_head != 0) {
        AnimationItem* next = m_head;
        m_head = m_head->getNext();
        if (m_head == 0)
            m_last = 0;
        return next;
    } else return 0;
}
