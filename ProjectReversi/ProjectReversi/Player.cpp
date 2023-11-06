#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(Color color) {
    this->color = color;
}

Color Player::getColor() {
    return color;
}

Cell* Player::getNextMove(Board* board) {
    // �R���\�[������΂�łʒu����͂���
    int x, y;
    cout << "Enter the coordinates for the next move (x y): ";
    cin >> x >> y;
    return new Cell(x, y);
}
