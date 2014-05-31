#ifndef GAMEBOARDWIDGET_H
#define GAMEBOARDWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include "gameboard.h"

class GameboardWidget : public QWidget
{
    Q_OBJECT
public:
    enum ChipColor {
        BLACK = 1,
        WHITE = 2
    };

    explicit GameboardWidget(const GameBoard* board, QWidget *parent = 0);

    QSize minimumSizeHint() const;
signals:

public slots:
    void activateHumanPlayer();
    void deactivateHumanPlayer();
    void chipDropAnimation();

protected:
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QImage m_gameboardImage;
    QImage m_redPiece;
    QImage m_blackPiece;
    QTimer *m_animationTimer;
    const GameBoard *m_board;

    int m_leftBoardOffset;
    int m_rightBoardOffset;
    int m_indexMultiplier;
    int m_boardWidth;
    int m_boardHeight;
    double m_animationTimeout;
    double m_animationVelocity;
    double m_animationAcceleration;

    double m_chipYPos;
    double m_chipXPos;
    bool m_isAnimating;
    ChipColor m_currentChipColor;

    int m_pieceIndex;
    bool m_humanPlayer;

};

#endif // GAMEBOARDWIDGET_H
