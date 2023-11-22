#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "Game.h"

int main() {
    //�l�ԃv���C���[��AI�v���C���[���쐬
    HumanPlayer* humanPlayer = new HumanPlayer(Color::WHITE);  // �l�ԃv���C���[�͔�
    AIPlayer* aiPlayer = new AIPlayer(Color::BLACK);  // AI�v���C���[�͍�

    //�Q�[�����J�n
    Game game(humanPlayer, aiPlayer);
    game.play();

    //�v���C���[�I�u�W�F�N�g��j��
    delete humanPlayer;
    delete aiPlayer;

    return 0;
}