#ifndef GAMEBOARDWIDGET_H
#define GAMEBOARDWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>

class GameboardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameboardWidget(QWidget *parent = 0);

    QSize minimumSizeHint() const;
signals:

public slots:
    void activateHumanPlayer();
    void deactivateHumanPlayer();

protected:
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent* event);

private:
    QImage m_gameboardImage;
    QImage m_redPiece;
    QImage m_blackPiece;

    int m_leftBoardOffset;
    int m_rightBoardOffset;
    int m_indexMultiplier;
    int m_boardWidth;
    int m_boardHeight;

    int m_pieceIndex;
    bool m_drawPiece;

};

#endif // GAMEBOARDWIDGET_H
