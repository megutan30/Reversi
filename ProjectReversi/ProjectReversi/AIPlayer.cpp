#include "AIPlayer.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>

using namespace std;

AIPlayer::AIPlayer(Color color) : Player(color) {
    srand(time(0));  // —”¶¬Ší‚Ì‰Šú‰»
}

Cell* AIPlayer::getNextMove(Board* board) {
    // ƒ‰ƒ“ƒ_ƒ€‚ÉÎ‚ğ‘Å‚ÂˆÊ’u‚ğ‘I‘ğ‚·‚é
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    return new Cell(x,y);
}
