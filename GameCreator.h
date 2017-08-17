#ifndef GAME_CREATOR_H
#define GAME_CREATOR_H

#include <array>

namespace PikiFamsGame { 

	using std::array;
	typedef std::array<int, 4> Array4Digits;

	class GameCreator {
	public:
		//4-digit number
		GameCreator(Array4Digits _guessingNumber) : guessingNumber(_guessingNumber) {}

	private:
		Array4Digits guessingNumber;
	};

}

#endif //GAME_CREATOR_H