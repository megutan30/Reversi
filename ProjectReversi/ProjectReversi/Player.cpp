#include "Player.h"
#include <iostream>

using namespace std;

/*�R���X�g���N�^*/
Player::Player(Color color) {
    this->color = color;
}

/*�v���C���[�̐F���擾*/
Color Player::getColor() {
    return color;
}
