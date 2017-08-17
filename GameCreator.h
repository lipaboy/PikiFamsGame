#ifndef GAME_CREATOR_H
#define GAME_CREATOR_H

#include <array>
#include <set>

namespace PikiFamsGame { 

	using std::array;
	typedef uint32_t Numbers;

	//You can use digits from 0 to 9
	//TODO: may be create set<int> with this numbers
	typedef std::array<Numbers, 4> Array4Digits;
	//std::set<int> Digits({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });

	struct GameStepInfo;

	class GameCreator {
	public:
		//4-digit number
		GameCreator(const Array4Digits& _guessingNumber);

		GameStepInfo guess(const Array4Digits& likelyNumber);

		uint32_t getStepCount() const { return stepCount; }

	private:
		Array4Digits guessingNumber;
		uint32_t stepCount = 0;
	};

	struct GameStepInfo {
		uint32_t piki;
		uint32_t fams;
	};

}

#endif //GAME_CREATOR_H