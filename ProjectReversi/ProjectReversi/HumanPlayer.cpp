#include "HumanPlayer.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

HumanPlayer::HumanPlayer(Color color) : Player(color) {
}

void HumanPlayer::moveCursor(int x, int y, COORD coord) {
    coord.X += x * 2 ;
    coord.Y += y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int HumanPlayer::getArrowKey() {
    int ch = _getch();
    if (ch == 0 || ch == 224) {
        ch = _getch();
    }
    return ch;
}

void HumanPlayer::convertCursorIntoBoardSize(int& x){
    if (x >= 0) {
        x %= BOARD_SIZE;
        return;
    }
    x = BOARD_SIZE - abs(x);
}

Cell* HumanPlayer::getNextMove(Board* board) {
    COORD coord;
    //�J�[�\���̏����ʒu
    coord.X = 3;
    coord.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    int x = 0;
    int y = 0;
    while (true) {
        switch (getArrowKey()) {

        case 72: // ����L�[
            --y;
            break;
        case 80: // �����L�[
            ++y;
            break;
        case 75: // �����L�[
            --x;
            break;
        case 77: // �E���L�[
            ++x;
            break;
        case 13: // �G���^�[�L�[
            return new Cell(x, y);
        }
        convertCursorIntoBoardSize(x);
        convertCursorIntoBoardSize(y);
        moveCursor(x, y,coord);
    }
}
/*TODO*/
//�J�[�\���̈ʒu
