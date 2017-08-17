#ifndef GAMEBOT_H
#define GAMEBOT_H

#include <iostream>

#include "GameCreator.h"

namespace PikiFamsGameBot {

	using namespace PikiFamsGame;



	//return game step count
	uint32_t solveTheGame(GameCreator game);

}

#endif //GAMEBOT_H
