#include "Board.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include "Console.h"

using namespace std;

/*�R���X�g���N�^*/
Board::Board() {
	//8x8��2�����z���������
	for (int x = 0; x < BOARD_SIZE; ++x) {
		for (int y = 0; y < BOARD_SIZE; ++y) {
			cells[x][y] = Cell();
		}
	}
	//�����ɏ����z�u�̐΂�u��
	cells[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1].setColor(Color::WHITE);
	cells[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2].setColor(Color::BLACK);
	cells[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1].setColor(Color::BLACK);
	cells[BOARD_SIZE / 2][BOARD_SIZE / 2].setColor(Color::WHITE);
}

/*�Ֆʕ\��*/
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
			//�u����ꏊ���ǂ������`�F�b�N
			//�����_�����g�p
			//������ꏊ�̃Z���Ƀ����_��(����͈�v���邩)��K�����āA
			//����炪�^�ƂȂ�v�f�T���Ă���
			//��v����Z����������΁AIt���̗v�f���w���C�e���[�^�[�ɂȂ�͂�
			//������Ȃ��Ȃ�end()���w���̂ł����ŏ�������
			auto it = find_if(validMoves.begin(), validMoves.end(), [=](const Cell* move) {
				return move->getX() == x && move->getY() == y;
				});

			//�u����ꏊ�͕�����悤�ɓ��ʕ\��
			if (it != validMoves.end()) {
				cout << "|*";
			}
			//����ȊO�͒ʏ�̕\��
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

/*�Z���ɐ΂�z�u����*/
void Board::placePiece(int x, int y, Color color) {
	cells[x][y].setColor(color);
}

/*�F����������Ԃ�*/
void Board::flipPieces(int x, int y, Color color) {
	//����̐F���擾
	Color opponent = (color == Color::WHITE) ? Color::BLACK : Color::WHITE;
	//�e�����`�F�b�N
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

/*�w�肳�ꂽ�ꏊ���u���邩�ǂ����𔻒肷��*/
bool Board::isValidMove(int x, int y, Color color) {
	//�͈͓��Ɏ��܂��Ă��邩
	if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
		return false;
	}
	//���͂��ꂽ�}�X���󂢂Ă��邩
	if (cells[x][y].getColor() != Color::EMPTY) {
		return false;
	}
	//���͂��ꂽ�}�X��1�}�X�ł���������Ԃ��邩
	//����̐F���擾
	Color opponent = (color == Color::WHITE) ? Color::BLACK : Color::WHITE;
	//�e�����`�F�b�N
	for (int i = 0; i < DIRNUM; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		bool hasOpponent = false;
		//�͈͓�������̃R�}�����������Ă���Ԃ͂��肩����
		while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && cells[nx][ny].getColor() == opponent) {
			hasOpponent = true;
			nx += dx[i];
			ny += dy[i];
		}
		//����̋����������ԂŎ����̐F���������ꍇ�Ɉ�������Ԃ���
		if (hasOpponent && nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && cells[nx][ny].getColor() == color) {
			return true;
		}
	}
	return false;
}

/*�Ђ����肩������ꏊ��z��ɂ��ēn��*/
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

/*�Q�[�����I���������ǂ����𔻒肷��*/
bool Board::isGameOver() {
	return getValidMoves(Color::BLACK).empty() && getValidMoves(Color::WHITE).empty();
}

/*�w�肵���F�̐΂̐��𐔂���*/
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