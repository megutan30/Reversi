#include"Console.h"

using namespace std;

/*コンストラクタ*/
Console::Console(){
    //カーソルの初期位置
    coord.X = initX;
    coord.Y = initY;
}

/*指定された場所にカーソルを移す*/
void Console::moveCursor(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}
