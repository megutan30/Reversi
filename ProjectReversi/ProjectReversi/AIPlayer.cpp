#include "AIPlayer.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

AIPlayer::AIPlayer(Color color) : Player(color) {
    srand(time(0));  // —”¶¬Ší‚Ì‰Šú‰»
}

Cell* AIPlayer::getNextMove(Board* board) {
    vector<Cell*> validMoves = board->getValidMoves(color);
    if (validMoves.empty()) {
        return nullptr;  // —LŒø‚Èè‚ª‚È‚¢ê‡
    }
    int index = rand() % validMoves.size();
    return validMoves[index];
}

