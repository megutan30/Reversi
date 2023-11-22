#include "Board.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include "Console.h"

using namespace std;

/*コンストラクタ*/
Board::Board() {
	//8x8の2次元配列を初期化
	for (int x = 0; x < BOARD_SIZE; ++x) {
		for (int y = 0; y < BOARD_SIZE; ++y) {
			cells[x][y] = Cell();
		}
	}
	//中央に初期配置の石を置く
	cells[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1].setColor(Color::WHITE);
	cells[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2].setColor(Color::BLACK);
	cells[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1].setColor(Color::BLACK);
	cells[BOARD_SIZE / 2][BOARD_SIZE / 2].setColor(Color::WHITE);
}

/*盤面表示*/
void Board::display() {
	vector<Cell*> validMoves = getValidMoves(Color::WHITE);
	cout << "  ";
	for (int x = 0; x < BOARD_SIZE; ++x) {
		cout << " " << x % BOARD_SIZE;
	}
	cout << endl;
	for (int y = 0; y < BOARD_SIZE; ++y) {
		cout << y % BOARD_SIZE << " ";
		for (int x = 0; x < BOARD_SIZE; ++x) {
			//置ける場所かどうかをチェック
			//ラムダ式を使用
			//おける場所のセルにラムダ式(今回は一致するか)を適応して、
			//それらが真となる要素探している
			//一致するセルが見つかれば、Itその要素を指すイテレーターになるはず
			//見つからないならend()を指すのでそこで条件分岐
			auto it = find_if(validMoves.begin(), validMoves.end(), [=](const Cell* move) {
				return move->getX() == x && move->getY() == y;
				});

			//置ける場所は分かるように特別表示
			if (it != validMoves.end()) {
				cout << "|*";
			}
			//それ以外は通常の表示
			else {
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
		}
		cout << "|" << endl;
	}
	cout << "  ";
	for (int x = 0; x < BOARD_SIZE; ++x) {
		cout << " " << x % BOARD_SIZE;
	}
	cout << endl;
}

/*セルに石を配置する*/
void Board::placePiece(int x, int y, Color color) {
	cells[x][y].setColor(color);
}

/*色を引っくり返す*/
void Board::flipPieces(int x, int y, Color color) {
	//相手の色を取得
	Color opponent = (color == Color::WHITE) ? Color::BLACK : Color::WHITE;
	//各方向チェック
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

/*指定された場所が置けるかどうかを判定する*/
bool Board::isValidMove(int x, int y, Color color) {
	//範囲内に収まっているか
	if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
		return false;
	}
	//入力されたマスが空いているか
	if (cells[x][y].getColor() != Color::EMPTY) {
		return false;
	}
	//入力されたマスが1マスでも引っくり返せるか
	//相手の色を取得
	Color opponent = (color == Color::WHITE) ? Color::BLACK : Color::WHITE;
	//各方向チェック
	for (int i = 0; i < DIRNUM; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		bool hasOpponent = false;
		//範囲内かつ相手のコマをが見つかっている間はくりかえす
		while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && cells[nx][ny].getColor() == opponent) {
			hasOpponent = true;
			nx += dx[i];
			ny += dy[i];
		}
		//相手の駒が見つかった状態で自分の色があった場合に引っくり返せる
		if (hasOpponent && nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && cells[nx][ny].getColor() == color) {
			return true;
		}
	}
	return false;
}

/*ひっくりかえせる場所を配列にして渡す*/
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

/*ゲームが終了したかどうかを判定する*/
bool Board::isGameOver() {
	return getValidMoves(Color::BLACK).empty() && getValidMoves(Color::WHITE).empty();
}

/*指定した色の石の数を数える*/
int Board::countPieces(Color color) {
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