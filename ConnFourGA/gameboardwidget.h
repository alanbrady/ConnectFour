#ifndef GAMEBOARDWIDGET_H
#define GAMEBOARDWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include "connectfourgame.h"
#include "animationqueue.h"


class GameboardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameboardWidget(QWidget *parent = 0);

    QSize minimumSizeHint() const;

signals:
    void humanMove(const int);
    void animationComplete();

public slots:
    void activateHumanPlayer(int color);
    void deactivateHumanPlayer();
    void moveMade(int move, int color, GameBoard board);
    void updateBoard(const GameBoard& gameBoard);

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
    GameBoard m_gameBoard;
//    GameBoard m_oldGameBoard;
    ConnectFourGame::PlayerColor m_currentPlayerColor;
    ConnectFourGame::PlayerColor m_animatedPlayerColor;
    AnimationItem* m_currentAnimation;
    AnimationQueue m_animationQueue;
    double m_chipBaseYPos;
    double m_bounces;
    double m_maxBounces;
    double m_bounceVelocityConstant;


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
    void startAnimation();


};

#endif // GAMEBOARDWIDGET_H
