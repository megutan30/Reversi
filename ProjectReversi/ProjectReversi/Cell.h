#ifndef CELL_H
#define CELL_H

#include "Color.h"

class Cell {
public:
    Cell();
    Cell(int x, int y);
    //ここは処理も記述した方が処理速度は上がりそうだが
    //見た目的にこっちのほうが綺麗なのでcppで定義
    int getX()const;
    int getY()const;
    Color getColor()const;
    void setColor(Color color);
private:
    int x;
    int y;
    Color color;
};

#endif