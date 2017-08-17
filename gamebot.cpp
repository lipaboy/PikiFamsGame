#include "gamebot.h"

#include <algorithm>

namespace PikiFamsGameBot {

	uint32_t solveTheGame(GameCreator game)
	{
		//Start
		GameSet digits = { set<DigitType>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}), 4 };

		//Everything starts with entering in cycle

		GameStepInfo info;

		do {
			GameSet setStep;
			Array4Digits appropriateStep;


			std::copy(setStep.plenty.begin(), setStep.plenty.end(), appropriateStep.begin());
			info = game.guess(appropriateStep);

		} while (info.fams < 4 && 0 == 1);

		//Wherever end of cycle

		return game.getStepCount();
	}

}
