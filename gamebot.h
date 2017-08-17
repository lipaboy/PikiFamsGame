#ifndef GAMEBOT_H
#define GAMEBOT_H

#include <iostream>

#include "GameCreator.h"

namespace PikiFamsGame {

	//return step count
	uint32_t solveTheGame(const GameCreator& game);

}

#endif //GAMEBOT_H
