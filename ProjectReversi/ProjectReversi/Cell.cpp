#include "Cell.h"

using namespace std;

/*�f�t�H���g�R���X�g���N�^*/
Cell::Cell() {
    this->x = 0;
    this->y = 0;
    this->color = Color::EMPTY;
}

/*�R���X�g���N�^*/
Cell::Cell(int x, int y) {
    this->x = x;
    this->y = y;
    this->color = Color::EMPTY;
}

/*X�����̉��}�X�ڂ��擾*/
int Cell::getX()const {
    return x;
}

/*Y�����̉��}�X�ډ��擾*/
int Cell::getY()const {
    return y;
}

/*�}�X�̐F���擾*/
Color Cell::getColor()const{
    return color;
}

/*�F���Z�b�g*/
void Cell::setColor(Color color) {
    this->color = color;
}
