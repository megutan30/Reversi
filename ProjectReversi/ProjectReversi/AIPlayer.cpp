#include "AIPlayer.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>

using namespace std;

AIPlayer::AIPlayer(Color color) : Player(color) {
    srand(time(0));  // ����������̏�����
}

Cell* AIPlayer::getNextMove(Board* board) {
    // �����_���ɐ΂�łʒu��I������
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    return new Cell(x,y);
}
