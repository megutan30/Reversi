#include "Player.h"
#include <iostream>

using namespace std;

/*コンストラクタ*/
Player::Player(Color color) {
    this->color = color;
    colorString = initColorString();
}

/*プレイヤーの色を取得*/
Color Player::getColor() const{
    return color;
}

/*プレイヤーの色を文字列として取得*/
string Player::getColorString()const {
    return colorString;
}

/*プレイヤーの色を文字列にする初期化*/
string Player::initColorString() const {
    switch (color) {
    case Color::EMPTY:
        return "Empty";
    case Color::BLACK:
        return "Black";
    case Color::WHITE:
        return "White";
    default:
        return "Unknown";
    }
}

