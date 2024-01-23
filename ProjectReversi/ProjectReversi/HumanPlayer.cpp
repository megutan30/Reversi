#include "HumanPlayer.h"
#include "GameLog.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_TAB 9

using namespace std;

/*コンストラクタ*/
HumanPlayer::HumanPlayer(Color color) : Player(color) {
    logEnabled = false;
}

/*十字キー取得*/
int HumanPlayer::getArrowKey() {
    int ch = _getch();
    if (ch == 0 || ch == 127) {
        ch = _getch();
    }
    return ch;
}

/*カーソルをボードの範囲内に変換*/
void HumanPlayer::convertCursorIntoBoardSize(int& x){
    //ボードの大きさを超えるとき剰余を算出
    if (x >= 0) {
        x %= BOARD_SIZE;
        return;
    }
    //マイナスになった際は最大値からマイナスの絶対値を産出
    x = BOARD_SIZE - abs(x); 
}

/*ログ表示フラグの取得*/
bool HumanPlayer::isLogEnabled() const {
    return logEnabled;
}

/*ログ表示フラグの切り替え*/
void HumanPlayer::toggleLog() {
    logEnabled = !logEnabled;
}

/*プレイヤーのムーブ*/
Cell* HumanPlayer::getNextMove(Board* board) {
    int x = 0;
    int y = 0;

    //初期カーソル配置
    //前のカーソル配置をそのままにした方がやりやすいかも
    console.moveCursor(console.initX,console.initY);
    while (true) {
        switch (getArrowKey()) {
        //上方向
        case KEY_UP:
        case KEY_W:
            --y;
            break;
        //下方向
        case KEY_DOWN:
        case KEY_S:
            ++y;
            break;
        //左方向
        case KEY_LEFT:
        case KEY_A:
            --x;
            break;
        //右方向
        case KEY_RIGHT:
        case KEY_D:
            ++x;
            break;
        //決定
        case KEY_ENTER:
            return new Cell(x, y);
        //ログ
        case KEY_TAB:
            toggleLog();
            if (isLogEnabled()) {
                console.moveCursor(0, BOARD_SIZE + 3);//盤面分ずらす
                GameLog::displayLog();
            }
            else
            {
                system("cls");
                board->display();
            }
        }
        
        convertCursorIntoBoardSize(x);
        convertCursorIntoBoardSize(y);
        console.moveCursor(x * 2 + console.initX, y + console.initY);//横幅は棒線をはさむのでニマス分動かす
    }
}
