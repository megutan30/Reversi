#include "Game.h"
#include <iostream>
#include <Windows.h>

using namespace std;

/*�R���X�g���N�^*/
Game::Game(Player* player1, Player* player2) {
	this->player1 = player1;
	this->player2 = player2;
	this->currentPlayer = player1;
}

/*�Q�[�����[�v*/
void Game::play() {
	while (true) {
		//�p�X�̏���
		if (board.getValidMoves(currentPlayer->getColor()).empty()){
			//�^�[����؂�ւ���
			switchPlayer();
		}
		//�Ֆʂ�\��
		board.display();

		//���݂̃v���C���[���΂�ł�
		Cell* nextMove = currentPlayer->getNextMove(&board);
		
		/*BUG*/
		//console.csbi.dwSize.Y��Console�̍s�����擾�ł���̂����A
		//SetConsoleCursorPosition�֐����N���A�����̂��ɕ`�悷�邽�߂��܂������Ȃ�
		//Windows�̎d�l�̂��߂��̕��@�͓����
		//�o�b�t�@���g�p���ăR���\�[�������擾����Ƃ���͂���ňÓ]���Ă��܂��̂�
		//��ʍX�V����x�ɂ܂Ƃ߂čs���悤�Ȍ`���悳����

		//�ł������\��
		console.moveCursor(0, console.csbi.dwSize.Y + 10);//�Ֆʂ̕`��ɍ��킹�Ă��̕��J�[�\����������
		cout << nextMove->getX() << "," << nextMove->getY() << endl;

		//�u���邩�ǂ������`�F�b�N
		if (board.isValidMove(nextMove->getX(), nextMove->getY(), currentPlayer->getColor())) {
			//�u�����ꏊ�𔽉f
			board.placePiece(nextMove->getX(), nextMove->getY(), currentPlayer->getColor());
			board.flipPieces(nextMove->getX(), nextMove->getY(), currentPlayer->getColor());
		}
		else {
			cout << "Invalid move. Try again." << endl;
			cin.clear();  // �G���[��Ԃ��N���A
			fseek(stdin, 0, SEEK_END);// ���̓o�b�t�@���N���A
			Sleep(1000);
			system("cls");
			continue;
		}

		//�Q�[���I������
		if (board.isGameOver()) {
			break;
		}

		//�^�[����؂�ւ���
		switchPlayer();

		/*ToDo*/
		//���̕ӂ̏����͌�X�v�ύX
		//�肪������悤�ɏ������Ԃ�u��
		Sleep(1000);
		system("cls");
	}

	//�Q�[���I�����Ɍ��ʂ�\��
	int player1Score = board.countPieces(player1->getColor());
	int player2Score = board.countPieces(player2->getColor());
	cout << "Player 1 score: " << player1Score << ", Player 2 score: " << player2Score << endl;
	if (player1Score > player2Score) {
		cout << "Player 1 wins!" << endl;
	}
	else if (player1Score < player2Score) {
		cout << "Player 2 wins!" << endl;
	}
	else {
		cout << "It's a draw!" << endl;
	}
}

/*���݂̃v���C���[�ύX*/
void Game::switchPlayer() {
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}