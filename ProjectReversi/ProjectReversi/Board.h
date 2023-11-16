#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include<vector>

const int BOARD_SIZE = 8;

class Board {
public:
    Board();
    void display();
    void placePiece(int x, int y, Color color);
    void flipPieces(int x, int y, Color color);
    bool isValidMove(int x, int y, Color color);
    std::vector<Cell*> getValidMoves(Color color);
    bool isGameOver();
    int countPieces(Color color);
    
private:
    Cell cells[BOARD_SIZE][BOARD_SIZE];
    const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    const int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    const int DIRNUM = 8;
};

#endif /* BOARD_H */
