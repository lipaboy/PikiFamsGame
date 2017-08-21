#include "gamebot.h"

#include <ctime>

namespace PikiFamsGameBot {

	uint32_t solveTheGame(GameCreator game)
	{
		std::srand(static_cast<uint32_t>(time(0)));
		//Start

		//Everything starts with entering in cycle

		GameSet digits(set<DigitType>({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }), stepLength);

		//TODO: read about reserve and clear: how you can use vector array without reallocation
		//TODO: think about what be better: vector or list. You need to sort out the array and delete items from it
		WorldSet world({ digits });		//world is a set of current GameSets
		StepStructure stepBuild;
		stepBuild.reserve(stepLength);

		GameSet stepSet;
		DigitArray appropriateStep;
		do {
			stepBuild.clear();
			stepSet.plenty.clear();

			//--------------------------Collect the necessary information----------------------------//

			//Take only one-set

			stepBuild.resize(1u);
			stepBuild[0].size = stepLength;

			WorldSet::iterator it;
			int minLength = INT_MAX;		//2 - it is our minimum (not 1)
			for (it = world.begin(); it != world.end(); it++) {
				if (it->plenty.size() > stepLength) {	//size == stepLength - is useless because we will know nothing new about that set
					PossibleResultInterval posResSet = calculatePossibleResultSet(*it, stepLength);
					int combinationCount = posResSet.right() - posResSet.left();	//signed int for unpredictable behavior
					//My criterion for selection best step
					if (combinationCount > 1 && combinationCount < minLength) {
						stepBuild[0].baseIt = it;
						minLength = combinationCount;
					}
				}
			}

			//--------------------------Combining the step--------------------------//

			for (uint32_t i = 0; i < stepBuild.size(); i++) {
				set<DigitType> plenty = stepBuild[i].baseIt->plenty;
				set<DigitType>::iterator it;
				for (uint32_t j = 0; j < stepBuild[i].size; j++) {
					it = plenty.begin();
					std::advance(it, rand() % plenty.size());
					stepSet.plenty.insert(*it);
					plenty.erase(it);
				}
			}

			//--------------------------Try to guess--------------------------//

			std::copy(stepSet.plenty.cbegin(), stepSet.plenty.cend(), appropriateStep.begin());
			GameStepInfo info = game.guess(appropriateStep);
			stepSet.value = info.fams + info.piki;
			if (stepSet.value >= stepLength)
				break;

			//Output

			std::cout << "Guess number: ";
			std::copy(appropriateStep.begin(), appropriateStep.end(),
				std::ostream_iterator<DigitType>(std::cout, " "));
			std::cout << ", " << stepSet.value << std::endl;

			//--------------------------Analyzing the step--------------------------//

			GameSet residue;

			//Works only at beginning two steps
			if (stepBuild.size() <= 1) {
				//1. Exclude from superset the stepSet to get residue
				const set<DigitType> & plenty = stepBuild[0].baseIt -> plenty;
				set<DigitType> temp;
				std::set_difference(plenty.cbegin(), plenty.cend(), 
					stepSet.plenty.cbegin(), stepSet.plenty.cend(), 
					std::inserter(temp, temp.begin()));

				residue.plenty = temp;
				residue.value = stepBuild[0].baseIt->value - stepSet.value;
				world.push_back(stepSet);
			}
			else {
				//1. exclude from stepSet sets that we use for combining this step 
				//and belong to world set (i.e. are the entire set)

				for (uint32_t i = 0; i < stepBuild.size(); i++) {
					const set<DigitType> & plenty = stepBuild[i].baseIt->plenty;
					if (plenty.size() == stepBuild[i].size) {	//if set that we use has size the same as its superset
						set<DigitType> temp;
						std::set_difference(stepSet.plenty.cbegin(), stepSet.plenty.cend(), 
							plenty.cbegin(), plenty.cend(), std::inserter(temp, temp.begin()));
						stepSet.plenty = temp;
						stepSet.value -= stepBuild[i].baseIt->value;
					}
				}

				residue = stepSet;
			}

			//2. Analysing the residue

			if (residue.plenty.size() == residue.value || 0 == residue.value) {
				set<DigitType>::iterator it;
				for (it = residue.plenty.cbegin(); it != residue.plenty.cend(); it++) {
					world.emplace_back(set<DigitType>({ *it }), 
						(residue.value > 0u));	//every set has value 1 (if set.size == value),
											//or 0 (if set.size == 0)
				}
			}

		} while (0 == 1);

		//Wherever end of cycle

		return game.getStepCount();
	}

	/*PossibleResultInterval calculatePossibleResultSet(const GameSet& set1)
	{
		return PossibleResultInterval();
	}*/

}
