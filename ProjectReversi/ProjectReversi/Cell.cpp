#include "Cell.h"

using namespace std;

/*デフォルトコンストラクタ*/
Cell::Cell() {
    this->x = 0;
    this->y = 0;
    this->color = Color::EMPTY;
}

/*コンストラクタ*/
Cell::Cell(int x, int y) {
    this->x = x;
    this->y = y;
    this->color = Color::EMPTY;
}

/*X方向の何マス目か取得*/
int Cell::getX()const {
    return x;
}

/*Y方向の何マス目化取得*/
int Cell::getY()const {
    return y;
}

/*マスの色を取得*/
Color Cell::getColor()const{
    return color;
}

/*色をセット*/
void Cell::setColor(Color color) {
    this->color = color;
}
