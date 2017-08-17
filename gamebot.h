#ifndef GAMEBOT_H
#define GAMEBOT_H

#include <iostream>
#include <set>

#include "GameCreator.h"

namespace PikiFamsGameBot {

	using PikiFamsGame::GameCreator;
	using PikiFamsGame::DigitType;
	using PikiFamsGame::Array4Digits;
	using PikiFamsGame::GameStepInfo;
	using std::set;

	//Special sets

	class GameSet {
	public:

	public:
		set<DigitType> plenty;
		uint32_t value;		//count digits that precense into that set
	};

	//return game step count
	uint32_t solveTheGame(GameCreator game);

}

#endif //GAMEBOT_H
