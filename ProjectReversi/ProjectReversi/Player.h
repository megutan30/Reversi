#ifndef PLAYER_H
#define PLAYER_H

#include "Cell.h"
#include "Board.h"
#include <string>

class Player {
public:
    Player(Color color);
    virtual Cell* getNextMove(Board* board) = 0;
    Color getColor() const;
    std::string getColorString() const;

protected:
    Color color;
    std::string colorString;
    std::string initColorString() const;
};

#endif
