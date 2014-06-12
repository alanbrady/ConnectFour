#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "gameboardwidget.h"
#include "connectfourgame.h"
#include "humanplayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void startGame();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GameboardWidget* m_gameboard;
    ConnectFourGame m_game;
    QThread* m_gameThread;

    HumanPlayer playerOne;
    HumanPlayer playerTwo;
};

#endif // MAINWINDOW_H
