#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_game.setPlayers(&playerOne, &playerTwo);

    QVBoxLayout* layout = new QVBoxLayout();
    m_gameboard = new GameboardWidget(this);
    layout->addWidget(m_gameboard);
    ui->centralWidget->setLayout(layout);

    connect(this, SIGNAL(startGame()), &m_game, SLOT(startGame()));

    connect(&m_game, SIGNAL(boardUpdated(GameBoard)),
            m_gameboard, SLOT(updateBoard(GameBoard)));
    connect(&m_game, SIGNAL(getHumanMove(ConnectFourGame::PlayerColor)),
            m_gameboard, SLOT(activateHumanPlayer(ConnectFourGame::PlayerColor)));
    connect(&m_game, SIGNAL(moveMade(int,PlayerColor)),
            m_gameboard, SLOT(moveMade(int,ConnectFourGame::PlayerColor)));
    connect(m_gameboard, SIGNAL(humanMove(int)),
            &m_game, SLOT(humanMoveMade(int)));
    m_gameThread = new QThread;
    m_game.moveToThread(m_gameThread);
    m_gameThread->start();

    emit startGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}
