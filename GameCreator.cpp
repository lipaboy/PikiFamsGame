#include "GameCreator.h"

#include <algorithm>

namespace PikiFamsGame {
	GameCreator::GameCreator(const Array4Digits& _guessingNumber)
	{
		std::transform(_guessingNumber.cbegin(), _guessingNumber.cend(),
			guessingNumber.begin(), [](int digit) -> int { return digit % 10; });
	}
}

