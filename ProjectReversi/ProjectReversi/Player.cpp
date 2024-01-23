#include "Player.h"
#include <iostream>

using namespace std;

/*�R���X�g���N�^*/
Player::Player(Color color) {
    this->color = color;
    colorString = initColorString();
}

/*�v���C���[�̐F���擾*/
Color Player::getColor() const{
    return color;
}

/*�v���C���[�̐F�𕶎���Ƃ��Ď擾*/
string Player::getColorString()const {
    return colorString;
}

/*�v���C���[�̐F�𕶎���ɂ��鏉����*/
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

