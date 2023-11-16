#include "AIPlayer.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

AIPlayer::AIPlayer(Color color) : Player(color) {
    srand(time(0));  // 乱数生成器の初期化
}

Cell* AIPlayer::getNextMove(Board* board) {
    vector<Cell*> validMoves = board->getValidMoves(color);
    if (validMoves.empty()) {
        return nullptr;  // 有効な手がない場合
    }
    int index = rand() % validMoves.size();
    return validMoves[index];
}

