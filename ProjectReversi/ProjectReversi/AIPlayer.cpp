#include "AIPlayer.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

/*コンストラクタ*/
AIPlayer::AIPlayer(Color color) : Player(color) {
    srand(time(0));  //乱数生成器の初期化
}

/*AIムーブ*/
Cell* AIPlayer::getNextMove(Board* board) {
    vector<Cell*> validMoves = board->getValidMoves(color);
    if (validMoves.empty()) {
        return nullptr;  //有効な手がない場合はヌルポインタ
    }
    //置ける場所からランダムに返す
    int index = rand() % validMoves.size();
    return validMoves[index];
}

