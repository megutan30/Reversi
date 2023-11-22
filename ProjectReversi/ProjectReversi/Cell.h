#ifndef CELL_H
#define CELL_H

#include "Color.h"

class Cell {
public:
    Cell();
    Cell(int x, int y);
    //�����͏������L�q���������������x�͏オ�肻������
    //�����ړI�ɂ������̂ق����Y��Ȃ̂�cpp�Œ�`
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