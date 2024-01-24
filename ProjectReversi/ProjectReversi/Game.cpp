#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define BUFFER_LEN 1000
/*ポート番号は任意のモノを設定*/
#define MY_PORT_NUM 55555

#include "Game.h"
#include "AIPlayer.h"
#include"HumanPlayer.h"
#include "Server.h"
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
	Server server;
	if (server.Initialize()) {
		cout << "WSAStartupの失敗。\n";
		return;
	}
	cout << "WSAStartupの成功。\n";

	if (server.OpenListenSocket() == false) {
		server.Close();
		cout << "失敗。\n";
		return;
	}

	SOCKET clientSocket = server.AcceptConnection();
	if (clientSocket == INVALID_SOCKET) {
		server.Close();
		return;
	}

	server.CloseListenSocket();
	char buffer[BUFFER_LEN];
	system("cls");
	bool isPlayerTurn = true;
	while (true) {
		board.display(currentPlayer->getColor());

		cout << "受信まち\n";
		Cell rcv = server.ReceiveData(clientSocket, buffer, sizeof(buffer));

		cout << rcv.getX()+","+rcv.getY()<<endl;

		if (strcmp(buffer, "end") == 0) {
			cout << "クライアントが切断\n";
			break;
		}

		//相手が置いた場所を反映
		board.placePiece(rcv.getX(), rcv.getY(), player2->getColor());
		board.flipPieces(rcv.getX(), rcv.getY(), player2->getColor());

		//相手が打った手をログに追加
		string action = currentPlayer->getColorString() + " plays at (" + to_string(rcv.getX()) + ", " + to_string(rcv.getY()) + ")";
		gameLog.addLog(action);

		//ボード表示
		system("cls");
		board.display(currentPlayer->getColor());

		//パスの処理
		if (board.getValidMoves(currentPlayer->getColor()).empty()) {
			//ターンを切り替える
			cout << "パス" << endl;
			system("cls");
		}

		while (1) {
			//プレイヤーが石を打つ
			Cell* nextMove = currentPlayer->getNextMove(&board);
			//置けるかどうかをチェック
			if (board.isValidMove(nextMove->getX(), nextMove->getY(), currentPlayer->getColor())) {
				//置いた場所を反映
				board.placePiece(nextMove->getX(), nextMove->getY(), currentPlayer->getColor());
				board.flipPieces(nextMove->getX(), nextMove->getY(), currentPlayer->getColor());

				//打った手を表示
				console.moveCursor((console.csbi.dwSize.X + BOARD_SIZE + 2) * 2, console.csbi.dwSize.Y + 2);//盤面の描画に合わせてその分カーソルを下げる
				if (currentPlayer == player1)cout << nextMove->getX() << "," << nextMove->getY() << endl;
				
				//打った手をログに追加
				string action = currentPlayer->getColorString() + " plays at (" + std::to_string(nextMove->getX()) + ", " + std::to_string(nextMove->getY()) + ")";
				gameLog.addLog(action);

				//送信
				buffer[0] = (char)nextMove->getX();
				buffer[1] = (char)nextMove->getY();
				buffer[2] = '\n';
				cout << "送信：" + buffer[0] + buffer[1] << endl;

				board.display(currentPlayer->getColor());
				server.SendData(clientSocket, buffer, int(strlen(buffer)));
				break;
			}
			else {
				cout << "置けないよm9(^Д^)ﾌﾟｷﾞｬｰもう一度起くといいよ( ´,_ゝ｀)ﾌﾟｯ" << endl;
				cin.clear();  //エラー状態をクリア
				fseek(stdin, 0, SEEK_END);//入力バッファをクリア
				Sleep(1000);
				system("cls");
				continue;
			}
		}
		
		//ゲーム終了判定
		if (board.isGameOver()) {
			break;
		}

		system("cls");
	}
	system("cls");
	board.display(currentPlayer->getColor());
	//ゲーム終了時に結果を表示
	int player1Score = board.countPieces(player1->getColor());
	int player2Score = board.countPieces(player2->getColor());
	cout << "Player 1 score: " << player1Score << ", Player 2 score: " << player2Score << endl;
	if (player1Score > player2Score) {
		cout << "お前の勝ちだ(　ﾟдﾟ)､ﾍﾟｯ" << endl;
	}
	else if (player1Score < player2Score) {
		cout << "雑魚乙w^^" << endl;
	}
	else {
		cout << "いやぁむずかったわぁ。引き分けにすんのｗ" << endl;
	}

	server.Close();
	cout << "本体終了\n";
}

/*現在のプレイヤー変更*/
void Game::switchPlayer() {
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}
