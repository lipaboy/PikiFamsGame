#include "gamebot.h"

#include <algorithm>
#include <vector>

namespace PikiFamsGameBot {

	using std::vector;
	
	uint32_t solveTheGame(GameCreator game)
	{
		//Start

		//Everything starts with entering in cycle

		GameSet digits(set<DigitType>({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }), 4u);

		vector<GameSet> world({ digits });		//world is a set of current GameSets
		GameStepInfo info;
		GameSet setStep;
		Array4Digits appropriateStep;
		do {
			//Collect the necessary information

			//take only one set
			vector<GameSet>::iterator it,
				bestGameSetIt = world.end();
			int minLength = INT_MAX;		//2 - it is our minimum (not 1)
			for (it = world.begin(); it != world.end(); it++) {
				if (it->plenty.size() >= 4) {
					PossibleResultInterval posResSet = calculatePossibleResultSet(*it, 4);
					int combinationCount = posResSet.right() - posResSet.left();
					if (combinationCount > 1 && combinationCount < minLength) {
						bestGameSetIt = it;
						minLength = combinationCount;
					}
				}
			}

			//Combining the step

			std::copy(setStep.plenty.begin(), setStep.plenty.end(), appropriateStep.begin());
			info = game.guess(appropriateStep);
			if (info.fams < 4)
				break;

			//Analyzing the step

		} while (0 == 1);

		//Wherever end of cycle

		return game.getStepCount();
	}

	/*PossibleResultInterval calculatePossibleResultSet(const GameSet& set1)
	{
		return PossibleResultInterval();
	}*/

}
