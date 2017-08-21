#ifndef GAME_CREATOR_H
#define GAME_CREATOR_H

#include <array>
#include <set>
#include <stdlib.h>
#include <time.h>

namespace PikiFamsGame { 

	using std::array;
	typedef uint32_t DigitType;
	constexpr uint32_t stepLength = 4u;

	//You can use digits from 0 to 9
	//TODO: may be create set<int> with this numbers
	typedef std::array<DigitType, stepLength> DigitArray;
	//std::set<int> Digits({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });

	struct GameStepInfo;

	class GameCreator {
	public:
		//4-digit number
		GameCreator(const DigitArray& _guessingNumber);
		GameCreator();

		GameStepInfo guess(const DigitArray& likelyNumber);

		uint32_t getStepCount() const { return stepCount; }

	private:
		DigitArray guessingNumber;
		uint32_t stepCount = 0;
	};

	struct GameStepInfo {
		uint32_t piki;
		uint32_t fams;
	};

}

#endif //GAME_CREATOR_H