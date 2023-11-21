#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "Game.h"

int main() {
    //人間プレイヤーとAIプレイヤーを作成
    HumanPlayer* humanPlayer = new HumanPlayer(Color::WHITE);  // 人間プレイヤーは白
    AIPlayer* aiPlayer = new AIPlayer(Color::BLACK);  // AIプレイヤーは黒

    //ゲームを開始
    Game game(humanPlayer, aiPlayer);
    game.play();

    //プレイヤーオブジェクトを破棄
    delete humanPlayer;
    delete aiPlayer;

    return 0;
}