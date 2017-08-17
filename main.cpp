#include <iostream>

#include "GameCreator.h"
#include "gamebot.h"

using namespace PikiFamsGame;
using namespace PikiFamsGameBot;

int main(void) {
	using std::cout;
	using std::endl;

	GameCreator game({ 1, 2, 3, 4 });

	//GameStepInfo info = game.guess({ 1, 0, 4, 9 });

	solveTheGame(game);

	//cout << info.piki << "piki " << info.fams << "fams" << endl;

	return 0;
}