#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"
#include "Console.h"

class Game {
public:
    Game(Player* player1, Player* player2);
    void play();
private:
    Player* player1;
    Player* player2;
    Board board;
    Player* currentPlayer;
    Console console;
    void switchPlayer();
};

#endif