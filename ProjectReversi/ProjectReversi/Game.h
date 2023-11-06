#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game {
public:
    Game(Player* player1, Player* player2);
    void play();
private:
    Player* player1;
    Player* player2;
    Board board;
    Player* currentPlayer;
};

#endif /* GAME_H */