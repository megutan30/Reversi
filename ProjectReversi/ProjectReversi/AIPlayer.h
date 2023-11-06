#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"
#include "Board.h"

class Board;

class AIPlayer : public Player {
public:
    AIPlayer(Color color);
    Cell* getNextMove(Board* board) override;
};

#endif /* AIPLAYER_H */