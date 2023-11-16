#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(Color color) {
    this->color = color;
}

Color Player::getColor() {
    return color;
}
