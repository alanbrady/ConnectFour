#include "gameboardwidget.h"
#include <QDebug>
#include <QMouseEvent>

GameboardWidget::GameboardWidget(QWidget *parent) :
    QWidget(parent)
{
    m_gameboardImage.load("game_board.png", "png");
    m_redPiece.load("red_piece.png", "png");
    m_blackPiece.load("black_piece.png", "png");

    setMouseTracking(true);
    m_humanPlayer = true;
    m_isAnimating = false;
    m_pieceIndex = 0;
    m_chipYPos = 0;

    m_leftBoardOffset = 14.8;
    m_rightBoardOffset = 10;
    m_topBoardOffset = 78;
    m_indexMultiplier = 60.1;
    m_boardWidth = 458;
    m_boardHeight = 460;
    m_animationTimeout = 10;
    m_gravAccel = 9.81;
    m_bounceVelocityConstant = 0.3;

    m_maxBounces = 5;

    m_animationTimer = new QTimer(this);
    connect (m_animationTimer, SIGNAL(timeout()),
             this, SLOT(chipDropAnimation()));
}

QSize GameboardWidget::minimumSizeHint() const
{
    return QSize(m_boardWidth, m_boardHeight);
}

void GameboardWidget::activateHumanPlayer(ConnectFourGame::PlayerColor color)
{
    m_humanPlayer = true;
    m_currentPlayerColor = color;
    setMouseTracking(true);
    update();
}

void GameboardWidget::deactivateHumanPlayer()
{
    m_humanPlayer = false;
    setMouseTracking(false);
    update();
}

void GameboardWidget::moveMade(int move, ConnectFourGame::PlayerColor color)
{
    m_chipYPos = 0;
    m_pieceIndex = move;
    m_currentPlayerColor = color;
    startAnimation();
}

void GameboardWidget::updateBoard(const GameBoard &gameBoard)
{
    m_gameBoard = gameBoard;
}

void GameboardWidget::chipDropAnimation()
{
    double time = (m_animationTimeMsecs/60);
    double newYPos = m_chipBaseYPos + m_animationVelocity*time +
            0.5*m_gravAccel*time*time;
    m_animationTimeMsecs += m_animationTimeout;
    update();
    if (newYPos > m_animationFloor) {
        m_animationVelocity = -1*m_gravAccel*time*m_bounceVelocityConstant;
        if (m_bounces >= m_maxBounces || (abs(m_animationVelocity) < 5)) {
            m_isAnimating = false;
            m_chipYPos = 0;
            m_animationTimer->stop();
//            if (m_humanPlayer) {
//                emit humanMove(m_pieceIndex);
//                deactivateHumanPlayer();
//            }
        } else {
            m_bounces++;
            m_animationTimeMsecs = m_animationTimeout;
            m_chipBaseYPos = m_animationFloor - (newYPos - m_animationFloor);
       }
    } else
        m_chipYPos = newYPos;
}

void GameboardWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

//    GameBoard board = m_game->getBoard();
    for (int row = 0; row < m_gameBoard.getRowCount(); row++) {
        GameBoardRow boardRow = m_gameBoard[row];
        for (int col = 0; col < m_gameBoard.getColCount(); col++) {
            if (boardRow[col] != ConnectFourGame::EMPTY) {
                QImage* chipImage = 0;
                if (boardRow[col] == ConnectFourGame::BLACK)
                    chipImage = &m_blackPiece;
                else
                    chipImage = &m_redPiece;
                double drawPieceY = m_boardHeight -
                        ((row*m_indexMultiplier)+m_topBoardOffset);
                double drawPieceX = (col*m_indexMultiplier)+m_leftBoardOffset;
                painter.drawImage(drawPieceX, drawPieceY, (*chipImage));
            }

        }
    }

    if (m_humanPlayer ) {
        QImage* currentPlayerColor = 0;
        if (m_currentPlayerColor == ConnectFourGame::BLACK)
            currentPlayerColor = &m_blackPiece;
        else if (m_currentPlayerColor == ConnectFourGame::RED)
            currentPlayerColor = &m_redPiece;

        if (currentPlayerColor != 0) {
            double drawPiecePos = (m_pieceIndex*m_indexMultiplier)+m_leftBoardOffset;
            painter.drawImage(drawPiecePos, m_chipYPos, (*currentPlayerColor));
        }
    }

    painter.drawImage(0, 60, m_gameboardImage);

}

void GameboardWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_humanPlayer && !m_isAnimating) {
        double mouseX = event->localPos().x();
        if (mouseX >= m_leftBoardOffset &&
            mouseX <= (m_boardWidth + m_rightBoardOffset)) {

            int newPieceIndex =
                    (mouseX - m_leftBoardOffset - m_rightBoardOffset)
                    /m_indexMultiplier;
            if (newPieceIndex < 7 && newPieceIndex != m_pieceIndex) {
                m_pieceIndex = newPieceIndex;
                update();
            }
        }
    }
}

void GameboardWidget::mouseReleaseEvent(QMouseEvent *)
{
    if (m_humanPlayer && !m_isAnimating) {
        emit humanMove(m_pieceIndex);
        deactivateHumanPlayer();
//        if (m_game->canMakeMove(m_pieceIndex)) {
//            startAnimation();
//        }
    }
}

double GameboardWidget::calculateAnimationFloor()
{
    int bottomIndex = 0;
//    GameBoard board = m_game->getBoard();
    while(m_gameBoard[bottomIndex][m_pieceIndex] != ConnectFourGame::EMPTY) {
        bottomIndex++;
    }
    if (bottomIndex >= m_gameBoard.getRowCount())
        return 0;
    return (m_boardHeight - ((bottomIndex*m_indexMultiplier)+m_topBoardOffset));
}

void GameboardWidget::startAnimation()
{
    m_animationFloor = calculateAnimationFloor();
    m_animationTimer->start(m_animationTimeout);
    m_isAnimating = true;
    m_animationTimeMsecs = 0;
    m_animationVelocity = 0;
    m_chipBaseYPos = 0;
    m_bounces = 0;
    update();
}
