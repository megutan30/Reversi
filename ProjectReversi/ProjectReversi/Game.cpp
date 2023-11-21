#include "Game.h"
#include <iostream>
#include <Windows.h>

using namespace std;

/*コンストラクタ*/
Game::Game(Player* player1, Player* player2) {
	this->player1 = player1;
	this->player2 = player2;
	this->currentPlayer = player1;
}

/*ゲームループ*/
void Game::play() {
	while (true) {
		//パスの処理
		if (board.getValidMoves(currentPlayer->getColor()).empty()){
			//ターンを切り替える
			switchPlayer();
		}
		//盤面を表示
		board.display();

		//現在のプレイヤーが石を打つ
		Cell* nextMove = currentPlayer->getNextMove(&board);
		
		/*BUG*/
		//console.csbi.dwSize.YでConsoleの行数を取得できるのだが、
		//SetConsoleCursorPosition関数がクリアしたのちに描画するためうまくいかない
		//Windowsの仕様のためこの方法は難しそう
		//バッファを使用してコンソール情報を取得するとそれはそれで暗転してしまうので
		//画面更新を一度にまとめて行うような形がよさそう

		//打った手を表示
		console.moveCursor(0, console.csbi.dwSize.Y + 10);//盤面の描画に合わせてその分カーソルを下げる
		cout << nextMove->getX() << "," << nextMove->getY() << endl;

		//置けるかどうかをチェック
		if (board.isValidMove(nextMove->getX(), nextMove->getY(), currentPlayer->getColor())) {
			//置いた場所を反映
			board.placePiece(nextMove->getX(), nextMove->getY(), currentPlayer->getColor());
			board.flipPieces(nextMove->getX(), nextMove->getY(), currentPlayer->getColor());
		}
		else {
			cout << "Invalid move. Try again." << endl;
			cin.clear();  // エラー状態をクリア
			fseek(stdin, 0, SEEK_END);// 入力バッファをクリア
			Sleep(1000);
			system("cls");
			continue;
		}

		//ゲーム終了判定
		if (board.isGameOver()) {
			break;
		}

		//ターンを切り替える
		switchPlayer();

		/*ToDo*/
		//この辺の処理は後々要変更
		//手が見えるように少し時間を置く
		Sleep(1000);
		system("cls");
	}

	//ゲーム終了時に結果を表示
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

/*現在のプレイヤー変更*/
void Game::switchPlayer() {
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}