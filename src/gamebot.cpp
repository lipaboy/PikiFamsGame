#include "gamebot.h"

#include <ctime>

namespace PikiFamsGameBot {
	
	uint32_t solveTheGame(GameCreator game)
	{
		std::srand(static_cast<uint32_t>(time(0)));
		//Start
		
		//Everything starts with entering in cycle

		GameSet digits(set<DigitType>({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }), 4u);

		//TODO: read about reserve and clear: how you can use vector array without reallocation
		//TODO: think about what be better: vector or list. You need to sort out the array and delete items from it
		WorldSet world({ digits });		//world is a set of current GameSets
		StepStructure stepBuild;
		stepBuild.reserve(4u);

		GameStepInfo info;
		set<DigitType> stepSet;
		Array4Digits appropriateStep;
		do {
			stepBuild.clear();
			stepSet.clear();

			//Collect the necessary information

			//Take only one-set

			stepBuild.resize(1u);
			stepBuild[0].size = 4u;

			WorldSet::iterator it;
			int minLength = INT_MAX;		//2 - it is our minimum (not 1)
			for (it = world.begin(); it != world.end(); it++) {
				if (it->plenty.size() >= 4) {
					PossibleResultInterval posResSet = calculatePossibleResultSet(*it, 4);
					int combinationCount = posResSet.right() - posResSet.left();	//signed int for unpredictable behavior
					if (combinationCount > 1 && combinationCount < minLength) {
						stepBuild[0].baseIt = it;
						minLength = combinationCount;
					}
				}
			}

			//Combining the step

			for (uint32_t i = 0; i < stepBuild.size(); i++) {
				set<DigitType> plenty = stepBuild[i].baseIt -> plenty;
				set<DigitType>::iterator it;
				for (uint32_t j = 0; j < stepBuild[i].size; j++) {
					it = plenty.begin();
					std::advance(it, rand() % plenty.size());
					stepSet.insert(*it);
					plenty.erase(it);
				}
			}

			//Try to guess

			std::copy(stepSet.begin(), stepSet.end(), appropriateStep.begin());
			info = game.guess(appropriateStep);
			uint32_t guessedCount = info.fams + info.piki;
			if (guessedCount >= 4)
				break;

			//Output

			std::cout << "Guess number: ";
			std::copy(appropriateStep.begin(), appropriateStep.end(), 
				std::ostream_iterator<DigitType>(std::cout, " "));
			std::cout << ", " << guessedCount << std::endl;


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
