#include "gameboardwidget.h"
#include <QDebug>
#include <QMouseEvent>

GameboardWidget::GameboardWidget(ConnectFourGame* game, QWidget *parent) :
    QWidget(parent), m_game(game)
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
    m_animationTimeout = 33.3;
    m_gravAccel = 9.81;

    m_animationTimer = new QTimer(this);
    connect (m_animationTimer, SIGNAL(timeout()),
             this, SLOT(chipDropAnimation()));
}

QSize GameboardWidget::minimumSizeHint() const
{
    return QSize(m_boardWidth, m_boardHeight);
}

void GameboardWidget::activateHumanPlayer()
{
    m_humanPlayer = true;
    setMouseTracking(true);
    update();
}

void GameboardWidget::deactivateHumanPlayer()
{
    m_humanPlayer = false;
    setMouseTracking(false);
    update();
}

void GameboardWidget::chipDropAnimation()
{
    double time = (m_animationTimeMsecs/100);
    m_chipYPos = 0.5*m_gravAccel*time*time;
    m_animationTimeMsecs += m_animationTimeout;
    update();
    if (m_chipYPos > m_animationFloor) {
        m_isAnimating = false;
        m_chipYPos = 0;
        m_animationTimer->stop();
    }
}

void GameboardWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawImage(0, 60, m_gameboardImage);

    GameBoard board = m_game->getBoard();
    for (int row = 0; row < board.getRowCount(); row++) {
        GameBoardRow boardRow = board[row];
        for (int col = 0; col < board.getColCount(); col++) {
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
        if (m_game->getCurrentPlayer() == ConnectFourGame::BLACK)
            currentPlayerColor = &m_blackPiece;
        else if (m_game->getCurrentPlayer() == ConnectFourGame::RED)
            currentPlayerColor = &m_redPiece;

        if (currentPlayerColor != 0) {
            double drawPiecePos = (m_pieceIndex*m_indexMultiplier)+m_leftBoardOffset;
            painter.drawImage(drawPiecePos, m_chipYPos, (*currentPlayerColor));
        }
    }

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
//        qDebug() << "pieceIndex" << m_pieceIndex;
        if (m_game->makeMove(m_pieceIndex, m_game->getCurrentPlayer())) {
            m_animationFloor = calculateAnimationFloor();
            m_animationTimer->start(m_animationTimeout);
            m_isAnimating = true;
            m_animationTimeMsecs = 0;
            update();
        }
    }
}

double GameboardWidget::calculateAnimationFloor()
{
    int bottomIndex = 0;
    GameBoard board = m_game->getBoard();
    while(board[bottomIndex][m_pieceIndex] != ConnectFourGame::EMPTY) {
        bottomIndex++;
    }
    if (bottomIndex >= board.getRowCount())
        return 0;
    return (m_boardHeight - ((bottomIndex*m_indexMultiplier)+m_topBoardOffset));
}
