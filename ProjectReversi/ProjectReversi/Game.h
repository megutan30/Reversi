#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"
#include "Console.h"
#include "GameLog.h"
#include "Server.h"
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
    GameLog gameLog;
    void switchPlayer();
};

#endif