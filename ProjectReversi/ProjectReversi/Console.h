#ifndef Console_H
#define Console_H

#include <windows.h>

class Console {
public:
	Console();
	COORD coord;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//カーソルの初期位置
	int const initX = 3;
	int const initY = 1;

	void moveCursor(int x, int y);
private:
};
#endif