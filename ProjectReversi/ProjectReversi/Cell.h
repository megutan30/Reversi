#ifndef CELL_H
#define CELL_H

#include "Color.h"

class Cell {
public:
    Cell();
    Cell(int x, int y);
    int getX();
    int getY();
    Color getColor();
    void setColor(Color color);
private:
    int x;
    int y;
    Color color;
};

#endif /* CELL_H */