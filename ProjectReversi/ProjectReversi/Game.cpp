#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(Player* player1, Player* player2) {
	this->player1 = player1;
	this->player2 = player2;
	this->currentPlayer = player1;
}

void Game::play() {
	while (true) {
		/*ToDo*/
		//パスの処理

		// 盤面を表示
		board.display();

		// 現在のプレイヤーが石を打つ
		Cell* nextMove = currentPlayer->getNextMove(&board);
		cout << nextMove->getX() << "," << nextMove->getY() << endl;

		if (board.isValidMove(nextMove->getX(), nextMove->getY(), currentPlayer->getColor())) {
			board.placePiece(nextMove->getX(), nextMove->getY(), currentPlayer->getColor());
			board.flipPieces(nextMove->getX(), nextMove->getY(), currentPlayer->getColor());
		}
		else {
			cout << "Invalid move. Try again." << endl;
			cin.clear();  // エラー状態をクリア
			fseek(stdin, 0, SEEK_END);
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 入力バッファをクリア
			continue;
		}

		// ゲーム終了判定
		if (board.isGameOver()) {
			break;
		}

		// ターンを切り替える
		currentPlayer = (currentPlayer == player1) ? player2 : player1;
	}

	// ゲーム終了時に結果を表示
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