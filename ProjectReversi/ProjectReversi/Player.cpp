#include "Player.h"
#include <iostream>

using namespace std;

/*コンストラクタ*/
Player::Player(Color color) {
    this->color = color;
}

/*プレイヤーの色を取得*/
Color Player::getColor() {
    return color;
}
