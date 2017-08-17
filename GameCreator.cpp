#include "GameCreator.h"

#include <algorithm>

namespace PikiFamsGame {
	GameCreator::GameCreator(const Array4Digits& _guessingNumber) : guessingNumber(_guessingNumber)
	{
		//TODO: all the digits must be different
	/*	std::transform(_guessingNumber.cbegin(), _guessingNumber.cend(),
			guessingNumber.begin(), [](int digit) -> int { return digit % 10; });*/
	}
	GameStepInfo GameCreator::guess(const Array4Digits & likelyNumber)
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
				}
			}
		}

		return info;
	}
}

