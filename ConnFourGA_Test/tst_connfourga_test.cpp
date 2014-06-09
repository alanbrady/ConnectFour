#include <QString>
#include <QtTest>
#include <QObject>

#include "connectfourgame.h"
#include "gameboard.h"
#include "gameboardrow.h"
#include "mockplayer.h"
#include "randomplayer.h"

Q_DECLARE_METATYPE(GameBoard)

class ConnFourGA_Test : public QObject
{
    Q_OBJECT
public:
    ConnFourGA_Test();

private Q_SLOTS:
    void connectFourGame_checkForWin();
    void connectFourGame_checkForWin_data();
    void connectFourGame_makeMove();
    void abstractPlayer_getPlayerMove();
    void abstractPlayer_getColor();
    void abstractPlayer_isHuman();
    void randomPlayer_getMove();
};

ConnFourGA_Test::ConnFourGA_Test()
{
    qRegisterMetaType<GameBoard>("GameBoard");
}

void ConnFourGA_Test::connectFourGame_checkForWin()
{
    QFETCH(GameBoard, board);
    QFETCH(bool, result);

    ConnectFourGame game(board);
    QCOMPARE(game.checkForWin(), result);
}

void ConnFourGA_Test::connectFourGame_checkForWin_data()
{
    QTest::addColumn<GameBoard>("board");
    QTest::addColumn<bool>("result");


    GameBoard board;
    QTest::newRow("blank")
            << board << false;

    board.clearBoard();
    board[0][0] = 1;
    board[0][1] = 1;
    board[0][2] = 1;
    board[0][3] = 1;
    QTest::newRow("bottom left row 1")
            << board << true;

    board.clearBoard();
    board[0][0] = -1;
    board[0][1] = -1;
    board[0][2] = -1;
    board[0][3] = -1;
    QTest::newRow("bottom left row -1")
            << board << true;

    board.clearBoard();
    board[0][0] = 1;
    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;
    QTest::newRow("bottom left diag right")
            << board << true;

    board.clearBoard();
    board[5][0] = 1;
    board[4][0] = 1;
    board[3][0] = 1;
    board[2][0] = 1;
    QTest::newRow("top left vertical")
            << board << true;

    board.clearBoard();
    board[5][6] = 1;
    board[4][6] = 1;
    board[3][6] = 1;
    board[2][6] = 1;
    QTest::newRow("top right vertical")
            << board << true;

    board.clearBoard();
    board[5][0] = 1;
    board[4][1] = 1;
    board[3][2] = 1;
    board[2][3] = 1;
    QTest::newRow("top left diag left")
            << board << true;

    board.clearBoard();
    board[5][0] = 1;
    board[4][0] = 1;
    board[3][0] = 1;
    QTest::newRow("top left vert 3")
            << board << false;

    board.clearBoard();
    board[5][6] = 1;
    board[4][5] = 1;
    board[3][4] = 1;
    QTest::newRow("top right diag right 3")
            << board << false;

    board.clearBoard();
    board[5][6] = 1;
    board[4][5] = 1;
    board[3][4] = 1;
    board[2][3] = 1;
    QTest::newRow("top right diag right 4")
            << board << true;

    board.clearBoard();
    board[5][6] = 1;
    board[4][5] = 1;
    board[3][4] = 1;
    board[2][3] = 1;
    board[1][2] = 1;
    QTest::newRow("top right diag right 5")
            << board << true;
}

void ConnFourGA_Test::connectFourGame_makeMove()
{
    ConnectFourGame game;
    game.makeMove(0, ConnectFourGame::BLACK);
    GameBoard board = game.getBoard();
    QCOMPARE(board[0][0], (int)ConnectFourGame::BLACK);

    game.makeMove(0, ConnectFourGame::RED);
    board = game.getBoard();
    QCOMPARE(board[0][0], (int)ConnectFourGame::BLACK);
    QCOMPARE(board[1][0], (int)ConnectFourGame::RED);

    board[2][0] = 1;
    board[3][0] = 1;
    board[4][0] = 1;
    board[5][0] = 1;
    game.setBoard(board);
    QVERIFY2(!(game.makeMove(0, ConnectFourGame::BLACK)),
             "Made an invalid move");

    QVERIFY(game.makeMove(-1, ConnectFourGame::BLACK) == false);
    QVERIFY(game.makeMove(7, ConnectFourGame::BLACK) == false);
}

void ConnFourGA_Test::abstractPlayer_getPlayerMove()
{
    GameBoard board;
    MockPlayer player(&board);

    int m = player.getPlayerMove();
    QVERIFY(m >= 0 && m <= 6);

}

void ConnFourGA_Test::abstractPlayer_getColor()
{
    GameBoard board;
    MockPlayer player(&board);

    QVERIFY(player.getColor() == ConnectFourGame::BLACK);
}

void ConnFourGA_Test::abstractPlayer_isHuman()
{
    GameBoard board;
    MockPlayer player(&board);

    QVERIFY(player.isHuman() == false);
}

void ConnFourGA_Test::randomPlayer_getMove()
{
    GameBoard board;
    RandomPlayer player;
    int move = player.getPlayerMove(board);
    QVERIFY(move >= 0 && move <= 6);
    move = player.getPlayerMove(board);
    QVERIFY(move >= 0 && move <= 6);
    move = player.getPlayerMove(board);
    QVERIFY(move >= 0 && move <= 6);
    move = player.getPlayerMove(board);
    QVERIFY(move >= 0 && move <= 6);
    move = player.getPlayerMove(board);
    QVERIFY(move >= 0 && move <= 6);
    move = player.getPlayerMove(board);
    QVERIFY(move >= 0 && move <= 6);
    move = player.getPlayerMove(board);
    QVERIFY(move >= 0 && move <= 6);
    move = player.getPlayerMove(board);
    QVERIFY(move >= 0 && move <= 6);
    move = player.getPlayerMove(board);
    QVERIFY(move >= 0 && move <= 6);
    move = player.getPlayerMove(board);
    QVERIFY(move >= 0 && move <= 6);
}

QTEST_APPLESS_MAIN(ConnFourGA_Test)

#include "tst_connfourga_test.moc"
