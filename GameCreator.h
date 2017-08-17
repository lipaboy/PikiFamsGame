#ifndef GAME_CREATOR_H
#define GAME_CREATOR_H

#include <array>
#include <set>

namespace PikiFamsGame { 

	using std::array;

	//You can use digits from 0 to 9
	//TODO: may be create set<int> with this numbers
	typedef std::array<int, 4> Array4Digits;
	std::set<int> Digits({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });

	class GameCreator {
	public:
		//4-digit number
		GameCreator(const Array4Digits& _guessingNumber);


	private:
		Array4Digits guessingNumber;
	};

}

#endif //GAME_CREATOR_H