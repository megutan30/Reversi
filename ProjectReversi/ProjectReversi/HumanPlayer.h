#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"
#include "Board.h"
#include <windows.h>
#include <conio.h>

class HumanPlayer : public Player {
public:
    HumanPlayer(Color color);
    Cell* getNextMove(Board* board) override;
    void moveCursor(int x, int y,COORD coord);
    void convertCursorIntoBoardSize(int& x);
    int getArrowKey();
};

#endif /* HUMAN_PLAYER_H */