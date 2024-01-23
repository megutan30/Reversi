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

/*�R���X�g���N�^*/
HumanPlayer::HumanPlayer(Color color) : Player(color) {
    logEnabled = false;
}

/*�\���L�[�擾*/
int HumanPlayer::getArrowKey() {
    int ch = _getch();
    if (ch == 0 || ch == 127) {
        ch = _getch();
    }
    return ch;
}

/*�J�[�\�����{�[�h�͈͓̔��ɕϊ�*/
void HumanPlayer::convertCursorIntoBoardSize(int& x){
    //�{�[�h�̑傫���𒴂���Ƃ���]���Z�o
    if (x >= 0) {
        x %= BOARD_SIZE;
        return;
    }
    //�}�C�i�X�ɂȂ����ۂ͍ő�l����}�C�i�X�̐�Βl���Y�o
    x = BOARD_SIZE - abs(x); 
}

/*���O�\���t���O�̎擾*/
bool HumanPlayer::isLogEnabled() const {
    return logEnabled;
}

/*���O�\���t���O�̐؂�ւ�*/
void HumanPlayer::toggleLog() {
    logEnabled = !logEnabled;
}

/*�v���C���[�̃��[�u*/
Cell* HumanPlayer::getNextMove(Board* board) {
    int x = 0;
    int y = 0;

    //�����J�[�\���z�u
    //�O�̃J�[�\���z�u�����̂܂܂ɂ����������₷������
    console.moveCursor(console.initX,console.initY);
    while (true) {
        switch (getArrowKey()) {
        //�����
        case KEY_UP:
        case KEY_W:
            --y;
            break;
        //������
        case KEY_DOWN:
        case KEY_S:
            ++y;
            break;
        //������
        case KEY_LEFT:
        case KEY_A:
            --x;
            break;
        //�E����
        case KEY_RIGHT:
        case KEY_D:
            ++x;
            break;
        //����
        case KEY_ENTER:
            return new Cell(x, y);
        //���O
        case KEY_TAB:
            toggleLog();
            if (isLogEnabled()) {
                console.moveCursor(0, BOARD_SIZE + 3);//�Ֆʕ����炷
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
        console.moveCursor(x * 2 + console.initX, y + console.initY);//�����͖_�����͂��ނ̂Ńj�}�X��������
    }
}
