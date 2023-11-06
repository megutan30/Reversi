#include "Board.h"
#include <iostream>

using namespace std;

Board::Board() {
    // 8x8の2次元配列を初期化
    for (int x = 0; x < BOARD_SIZE; ++x) {
        for (int y = 0; y < BOARD_SIZE; ++y) {
            cells[x][y] = Cell();
        }
    }
    // 中央に初期配置の石を置く
    cells[BOARD_SIZE/ 2 - 1][BOARD_SIZE/2-1].setColor(Color::WHITE);
    cells[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2].setColor(Color::BLACK);
    cells[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1].setColor(Color::BLACK);
    cells[BOARD_SIZE / 2][BOARD_SIZE / 2].setColor(Color::WHITE);
}

void Board::display() {
    cout << "  ";
    for (int x = 0; x < BOARD_SIZE; ++x) {
        cout << " " << x % BOARD_SIZE;
    }
    cout << endl;
    for (int y = 0; y < BOARD_SIZE; ++y) {
        cout << y % BOARD_SIZE << " ";
        for (int x = 0; x < BOARD_SIZE; ++x) {
            if (cells[x][y].getColor() == Color::EMPTY) {
                cout << "| ";
            }
            else if (cells[x][y].getColor() == Color::WHITE) {
                cout << "|W";
            }
            else if (cells[x][y].getColor() == Color::BLACK) {
                cout << "|B";
            }
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int x = 0; x < BOARD_SIZE; ++x) {
        cout << " " << x % BOARD_SIZE;
    }
    cout << endl;
}

void Board::placePiece(int x, int y, Color color) {
    // セルに石を配置する
    cells[x][y].setColor(color);
}

void Board::flipPieces(int x, int y, Color color) {
    for (int i = 0; i < DIRNUM; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        while (nx >= 0 && nx < DIRNUM && ny >= 0 && ny < DIRNUM && cells[nx][ny].getColor() != color) {
            nx += dx[i];
            ny += dy[i];
        }
        if (nx >= 0 && nx < DIRNUM && ny >= 0 && ny < DIRNUM && cells[nx][ny].getColor() == color) {
            while (nx != x || ny != y) {
                nx -= dx[i];
                ny -= dy[i];
                cells[nx][ny].setColor(color);
            }
        }
    }
}

bool Board::isValidMove(int x, int y, Color color) {
    //ToDo
    //間に空白がある場所は置けないように
    //
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return false;
    }
    if (cells[x][y].getColor() != Color::EMPTY) {
        return false;
    }
    for (int i = 0; i < DIRNUM; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        while (nx >= 0 && nx < DIRNUM && ny >= 0 && ny < DIRNUM && cells[nx][ny].getColor() != color) {
            nx += dx[i];
            ny += dy[i];
        }
        if (nx >= 0 && nx < DIRNUM && ny >= 0 && ny < DIRNUM && cells[nx][ny].getColor() == color) {
            return true;
        }
    }
    return false;
}

bool Board::isGameOver() {
    // ゲームが終了したかどうかを判定する
    // ...
    return false;
}

int Board::countPieces(Color color) {
    // 指定した色の石の数を数える
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (cells[i][j].getColor() == color) {
                ++count;
            }
        }
    }
    return count;
}