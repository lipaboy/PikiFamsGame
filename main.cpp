#include <iostream>

#include "GameCreator.h"

using namespace PikiFamsGame;

int main(void) {
	using std::cout;
	using std::endl;

	GameCreator game({ 1, 2, 3, 4 });

	GameStepInfo info = game.guess({ 1, 0, 4, 9 });

	cout << info.piki << "piki " << info.fams << "fams" << endl;

	return 0;
}