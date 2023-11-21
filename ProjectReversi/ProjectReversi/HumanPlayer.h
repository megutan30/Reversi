#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"
#include "Board.h"
#include "Console.h"
#include <windows.h>
#include <conio.h>
class HumanPlayer : public Player {
public:
    HumanPlayer(Color color);
    Cell* getNextMove(Board* board) override;
private:
    void convertCursorIntoBoardSize(int& x);
    int getArrowKey();
    Console console;
};

#endif