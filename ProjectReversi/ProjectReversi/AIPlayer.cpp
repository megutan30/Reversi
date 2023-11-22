#include "AIPlayer.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

/*�R���X�g���N�^*/
AIPlayer::AIPlayer(Color color) : Player(color) {
    srand(time(0));  //����������̏�����
}

/*AI���[�u*/
Cell* AIPlayer::getNextMove(Board* board) {
    vector<Cell*> validMoves = board->getValidMoves(color);
    if (validMoves.empty()) {
        return nullptr;  //�L���Ȏ肪�Ȃ��ꍇ�̓k���|�C���^
    }
    //�u����ꏊ���烉���_���ɕԂ�
    int index = rand() % validMoves.size();
    return validMoves[index];
}

