#include "Board.h"
#include <iostream>
#include <vector>

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
    system("cls");//画面クリア

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
    Color opponent = (color == Color::WHITE) ? Color::BLACK : Color::WHITE;
    for (int i = 0; i < DIRNUM; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        bool hasOpponent = false;
        while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && cells[nx][ny].getColor() == opponent) {
            hasOpponent = true;
            nx += dx[i];
            ny += dy[i];
        }
        if (hasOpponent && nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && cells[nx][ny].getColor() == color) {
            nx -= dx[i];
            ny -= dy[i];
            while (nx != x || ny != y) {
                cells[nx][ny].setColor(color);
                nx -= dx[i];
                ny -= dy[i];
            }
        }
    }
}

bool Board::isValidMove(int x, int y, Color color) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return false;
    }
    if (cells[x][y].getColor() != Color::EMPTY) {
        return false;
    }
    Color opponent = (color == Color::WHITE) ? Color::BLACK : Color::WHITE;
    for (int i = 0; i < DIRNUM; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        bool hasOpponent = false;
        while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && cells[nx][ny].getColor() == opponent) {
            hasOpponent = true;
            nx += dx[i];
            ny += dy[i];
        }
        if (hasOpponent && nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && cells[nx][ny].getColor() == color) {
            return true;
        }
    }
    return false;
}

vector<Cell*> Board::getValidMoves(Color color) {
    vector<Cell*> validMoves;
    for (int x = 0; x < BOARD_SIZE; ++x) {
        for (int y = 0; y < BOARD_SIZE; ++y) {
            if (isValidMove(x, y, color)) {
                validMoves.push_back(new Cell(x, y));
            }
        }
    }
    return validMoves;
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