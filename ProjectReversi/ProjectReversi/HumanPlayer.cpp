#include "HumanPlayer.h"
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer(Color color) : Player(color) {
}

Cell* HumanPlayer::getNextMove(Board* board) {
    // コンソールから石を打つ位置を入力する
    int x, y;
    cout << "Enter the coordinates for the next move (x y): ";
    cin >> x >> y;
    return new Cell(x, y);
}
