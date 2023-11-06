#include "Cell.h"

using namespace std;

Cell::Cell() {
    this->x = 0;
    this->y = 0;
    this->color = Color::EMPTY;  // ‰Šúó‘Ô‚Í‹ó
}

Cell::Cell(int x, int y) {
    this->x = x;
    this->y = y;
    this->color = Color::EMPTY;  // ‰Šúó‘Ô‚Í‹ó
}

int Cell::getX() {
    return x;
}

int Cell::getY() {
    return y;
}

Color Cell::getColor() {
    return color;
}

void Cell::setColor(Color color) {
    this->color = color;
}
