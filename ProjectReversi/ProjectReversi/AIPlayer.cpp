#include "AIPlayer.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

AIPlayer::AIPlayer(Color color) : Player(color) {
    srand(time(0));  // ����������̏�����
}

Cell* AIPlayer::getNextMove(Board* board) {
    vector<Cell*> validMoves = board->getValidMoves(color);
    if (validMoves.empty()) {
        return nullptr;  // �L���Ȏ肪�Ȃ��ꍇ
    }
    int index = rand() % validMoves.size();
    return validMoves[index];
}

