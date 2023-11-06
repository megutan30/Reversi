#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"
#include "Board.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(Color color);
    Cell* getNextMove(Board* board) override;
};

#endif /* HUMAN_PLAYER_H */