#ifndef GAMEBOARDWIDGET_H
#define GAMEBOARDWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include "connectfourgame.h"


class GameboardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameboardWidget(ConnectFourGame* game, QWidget *parent = 0);

    QSize minimumSizeHint() const;

public slots:
    void activateHumanPlayer();
    void deactivateHumanPlayer();

private slots:
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
    double m_animationTimeMsecs;
    double m_animationFloor;
    ConnectFourGame *m_game;

    double m_leftBoardOffset;
    double m_rightBoardOffset;
    double m_topBoardOffset;
    double m_indexMultiplier;
    int m_boardWidth;
    int m_boardHeight;
    double m_animationTimeout;
    double m_animationVelocity;
    double m_animationAcceleration;

    double m_floor;
    double m_chipYPos;
    double m_chipXPos;
    bool m_isAnimating;
//    ConnectFourGame::PlayerColor m_currentChipColor;
    double m_gravAccel;

    int m_pieceIndex;
    bool m_humanPlayer;

    double calculateAnimationFloor();



};

#endif // GAMEBOARDWIDGET_H
