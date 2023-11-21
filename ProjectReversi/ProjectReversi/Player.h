#ifndef PLAYER_H
#define PLAYER_H

#include "Cell.h"
#include "Board.h"

class Player {
public:
    Player(Color color);
    virtual Cell* getNextMove(Board* board) = 0;
    Color getColor();

protected:
    Color color;
};

#endif
