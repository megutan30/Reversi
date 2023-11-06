#include "AIPlayer.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>

using namespace std;

AIPlayer::AIPlayer(Color color) : Player(color) {
    srand(time(0));  // 乱数生成器の初期化
}

Cell* AIPlayer::getNextMove(Board* board) {
    // ランダムに石を打つ位置を選択する
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    return new Cell(x,y);
}
