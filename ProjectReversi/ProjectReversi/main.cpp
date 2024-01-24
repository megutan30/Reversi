#include "Game.h"
#include"HumanPlayer.h"
#include"AIPlayer.h"

using namespace std;

int main()
{
	HumanPlayer* Player1 = new HumanPlayer(Color::WHITE);
	HumanPlayer* Player2 = new HumanPlayer(Color::BLACK);
	
	Game game(Player1, Player2);
	game.play();

	delete Player1;
	delete Player2;
}