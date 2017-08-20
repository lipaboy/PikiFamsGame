#include <iostream>

#include "GameCreator.h"
#include "gamebot.h"

using namespace PikiFamsGame;
using namespace PikiFamsGameBot;

int main(void) {
	using std::cout;
	using std::endl;

	GameCreator game({ 1, 2, 3, 4 });
	GameCreator game2;

	//GameStepInfo info = game.guess({ 1, 0, 4, 9 });

	//solveTheGame(game);

	PossibleResultInterval pos =
		calculatePossibleResultSet(GameSet(set<DigitType>({ 0, 1, 2 }), 2u), 2u);
	cout << pos.left() << " " << pos.right() << endl;

	//cout << info.piki << "piki " << info.fams << "fams" << endl;

	return 0;
}