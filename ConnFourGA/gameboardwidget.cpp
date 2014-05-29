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
    m_drawPiece = true;
    m_pieceIndex = 0;

    m_leftBoardOffset = 10;
    m_rightBoardOffset = 10;
    m_indexMultiplier = 61.43;
    m_boardWidth = 451;
    m_boardHeight = 460;
}

QSize GameboardWidget::minimumSizeHint() const
{
    return QSize(m_boardWidth, m_boardHeight);
}

void GameboardWidget::activateHumanPlayer()
{
    // TODO
}

void GameboardWidget::deactivateHumanPlayer()
{
    // TODO
}

void GameboardWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawImage(0, 60, m_gameboardImage);

    if (m_drawPiece) {
        qDebug() << "Piece Index: " << m_pieceIndex;
        double drawPiecePos = (m_pieceIndex*m_indexMultiplier)+m_leftBoardOffset;
        painter.drawImage(drawPiecePos, 0, m_redPiece);
    }

}

void GameboardWidget::mouseMoveEvent(QMouseEvent *event)
{
    double mouseX = event->localPos().x();
    if (mouseX >= m_leftBoardOffset &&
        mouseX <= (m_boardWidth + m_rightBoardOffset)) {

        int newPieceIndex =
                (mouseX - m_leftBoardOffset - m_rightBoardOffset)/m_indexMultiplier;
        if (newPieceIndex < 7 && newPieceIndex != m_pieceIndex) {
            m_pieceIndex = newPieceIndex;
            update();
        }
    }
}
