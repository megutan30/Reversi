#include"Console.h"

using namespace std;

/*�R���X�g���N�^*/
Console::Console(){
    //�J�[�\���̏����ʒu
    coord.X = initX;
    coord.Y = initY;
}

/*�w�肳�ꂽ�ꏊ�ɃJ�[�\�����ڂ�*/
void Console::moveCursor(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}
