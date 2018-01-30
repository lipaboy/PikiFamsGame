#include "GameCreator.h"

#include <algorithm>
#include <list>
#include <iostream>
#include <iterator>

namespace PikiFamsGame {
	GameCreator::GameCreator(const DigitArray& _guessingNumber) : guessingNumber(_guessingNumber)
	{
		//TODO: all the digits must be different
	/*	std::transform(_guessingNumber.cbegin(), _guessingNumber.cend(),
			guessingNumber.begin(), [](int digit) -> int { return digit % 10; });*/
	}

	GameCreator::GameCreator()
	{
		using std::list;
		time_t t;
		srand((unsigned)time(&t));
		list<DigitType> digits({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
		list<DigitType>::iterator it;
		for (uint32_t i = 0; i < guessingNumber.size(); i++) {
			it = digits.begin();
			std::advance(it, rand() % digits.size());
			guessingNumber[i] = *it;
			digits.erase(it, it);
		}

		/*std::copy(guessingNumber.cbegin(), guessingNumber.cend(), 
			std::ostream_iterator<DigitType>(std::cout, " "));*/
	}

	GameStepInfo GameCreator::guess(const DigitArray & likelyNumber)
	{
		GameStepInfo info = { 0, 0 };

		stepCount++;

		for (uint32_t i = 0; i < guessingNumber.size(); i++) {
			for (uint32_t j = 0; j < likelyNumber.size(); j++) {
				if (guessingNumber[i] == likelyNumber[j]) {
					if (i == j)
						++(info.piki);
					else
						++(info.fams);
					break;
				}
			}
		}

		return info;
	}
}

